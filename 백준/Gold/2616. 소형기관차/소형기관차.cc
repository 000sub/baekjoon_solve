#include <bits/stdc++.h>
#define PII pair<int,int>

using namespace std;

int pSum[50001], dp[3][50001];
int n, k;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> pSum[i];
		pSum[i] += pSum[i - 1];
	}
	cin >> k;

	dp[0][1] = pSum[1];
	for (int i = k; i <= n; i++) {
		dp[0][i] = dp[0][i - 1];
		dp[0][i] = max(dp[0][i], pSum[i] - pSum[i - k]);
		
		dp[1][i] = dp[1][i - 1];
		dp[1][i] = max(dp[1][i], dp[0][i - k] + pSum[i] - pSum[i - k]);
		
		dp[2][i] = dp[2][i - 1];
		dp[2][i] = max(dp[2][i], dp[1][i - k] + pSum[i] - pSum[i - k]);
	}

	cout << dp[2][n];
	
	return 0;
}