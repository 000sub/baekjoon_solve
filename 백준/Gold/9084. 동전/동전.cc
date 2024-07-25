#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#define PII pair<int,int>

using namespace std;
typedef long long ll;

int t, n, m;
int coins[21];
int dp[10001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> t;
	
	for (int tc = 0; tc < t; tc++) {
		cin >> n;
		for (int i = 0; i < n; i++) cin >> coins[i];
		cin >> m;

		memset(dp, 0, sizeof(dp));

		dp[0] = 1;

		for (int i = 0; i < n; i++) {
			for (int j = coins[i]; j <= m; j++) {
				dp[j] += dp[j - coins[i]];
			}
		}

		cout << dp[m] << '\n';
	}

	return 0;
}