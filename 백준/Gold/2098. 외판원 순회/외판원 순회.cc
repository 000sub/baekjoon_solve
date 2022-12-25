#include <iostream>
#include <algorithm>
#include <cstring>


using namespace std;
int n, W[16][16], dp[16][1<<16];

int make_dp(int cur, int state){
	
	if (dp[cur][state] != -1) return dp[cur][state];
	
	if (state == (1<<n)-1) {
		if (W[cur][1] != 0) return W[cur][1];
		else return 1e9;
	}
	
	dp[cur][state] = 1e9;
	for (int i=0; i<n; i++){
		if ((1<<i) & state || W[cur][i] == 0) continue;
		dp[cur][state] = min(dp[cur][state], make_dp(i, (state | (1<<i))) + W[cur][i]);
	}
	
	return dp[cur][state];
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int ans;
	
	cin>>n;
	for (int i=0; i<n; i++){
		for (int j=0; j<n; j++){
			cin>>W[i][j];
		}
	}
	
	memset(dp, -1, sizeof(dp));
	
	ans = make_dp(1, 2);
	cout<<ans<<'\n';
	
	return 0;
}