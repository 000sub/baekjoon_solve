#include <iostream>
#include <queue>
#define PII pair<int,int>
using namespace std;

int N;
int dp[100001][3];
constexpr int MOD = 9901;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>N;

	dp[1][0] = dp[1][1] = dp[1][2] = 1;

	for (int i=2; i<=N; i++) {
		dp[i][0] = dp[i-1][0] + dp[i-1][1] + dp[i-1][2];
		dp[i][1] = dp[i-1][0] + dp[i-1][2];
		dp[i][2] = dp[i-1][0] + dp[i-1][1];

		dp[i][0]%=MOD;
		dp[i][1]%=MOD;
		dp[i][2]%=MOD;
	}

	int ans = dp[N][0] + dp[N][1] + dp[N][2];
	cout<<ans%MOD;
	return 0;
}