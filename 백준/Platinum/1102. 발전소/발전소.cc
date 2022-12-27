#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

int n, p, cnt = 0, arr[16][16], dp[1<<16];
char state[16];

int make_dp(int _cnt, int _state){
	if (_cnt == p) return 0;
	if (_state == 0) return -1;
	if (dp[_state] != 1e9) return dp[_state];
	
	for (int i=0; i<n; i++){
		if ((_state & 1<<(n-i-1)) == 0) continue;
		
		for (int j=0; j<n; j++){
			if ((_state & 1<<(n-j-1)) == 0) {
				dp[_state] = min(dp[_state], arr[i][j] + make_dp(_cnt+1, (_state | 1<<(n-j-1))));
			}
		}
	}
	
	return dp[_state];
}


int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int cur_state = 0;
	int ans;
	
	cin >> n;
	for (int i=0; i<n; i++){
		for (int j=0; j<n; j++){
			cin >> arr[i][j];
		}
	}
	
	for (int i=0; i<n; i++){
		cin >> state[i];
		if (state[i] == 'Y') {
			cnt++;
			cur_state += (1<< (n-i-1));
		}
	}
	cin>>p;
	
	fill(dp, dp + (1<<16), 1e9);
	
	cnt >= p ? ans = 0 : ans = make_dp(cnt, cur_state);
	cout<<ans;
	
	return 0;
}