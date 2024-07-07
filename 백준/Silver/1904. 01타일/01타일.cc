#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

typedef long long ll;
using namespace std;

const int MOD = 15746;

//8MB
int dp[1000001][2];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	int n;
	cin>>n;
	dp[1][1] = 1; dp[2][0] = 1; dp[2][1] = 1;
	for (int i=3; i<=n; i++) {
		dp[i][0] = (dp[i-2][0] + dp[i-2][1]) % MOD;
		dp[i][1] = (dp[i-1][0] + dp[i-1][1]) % MOD;
	}
	
	cout<<(dp[n][0]+dp[n][1])%MOD;
}