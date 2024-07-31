#include <bits/stdc++.h>

#define PII pair<int,int>

using namespace std;
typedef long long ll;

int dp[51];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n;
	cin >> n;
	dp[0] = 1;
	dp[1] = 1;
	for (int i = 2; i <= n; i++) {
		dp[i] = dp[i - 1] + dp[i - 2] + 1;
		dp[i] %= 1'000'000'007;
	}
	
	cout << dp[n];
	
	return 0;
}