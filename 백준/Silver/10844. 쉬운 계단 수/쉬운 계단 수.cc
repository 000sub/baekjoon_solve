#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int N;
	ll dp[101][10], ans = 0;
	
	cin>>N;
	
	memset(dp, 0, sizeof(dp));
	
	for (int i=1; i<10; i++) dp[1][i] = 1;
	
	for (int i=2; i<=N; i++){
		dp[i][0] = dp[i-1][1];
		dp[i][9] = dp[i-1][8];
		
		for (int j=1; j<9; j++){
			dp[i][j] = (dp[i-1][j-1] + dp[i-1][j+1]) % 1000000000; 
		}
	}
	
	for (int i=0; i<10; i++) ans+=dp[N][i];
	ans = ans % 1000000000;
	cout<<ans;
	
	return 0;
}