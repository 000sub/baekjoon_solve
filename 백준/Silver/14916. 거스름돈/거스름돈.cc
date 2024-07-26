#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#define PII pair<int,int>

using namespace std;
typedef long long ll;

int dp[100001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n;
	cin >> n;
	fill(dp, dp + 100001, 1e9);

	dp[2] = 1, dp[4] = 2, dp[5] = 1;

	for (int i = 6; i <= n; i++) {
		dp[i] = min(dp[i - 2] + 1, dp[i - 5] + 1);
	}

	dp[n] == 1e9 ? cout << -1 : cout << dp[n];

	return 0;
}