#include <bits/stdc++.h>

#define PII pair<int,int>

using namespace std;
typedef long long ll;

ll dp[100001][10];
constexpr ll mod = 987'654'321;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n;
	cin >> n;
	if (n == 1) {
		cout << 9;
		return 0;
	}

	for (int i = 1; i <= 9; i++) dp[1][i] = 1;

	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= 9; j++) {
			for (int k = -2; k <= 2; k++) {
				if (j + k < 1 || j + k > 9) continue;
				dp[i][j] += dp[i - 1][j + k];
				dp[i][j] %= mod;
			}
		}
	}

	ll ans = 0;

	for (int i = 1; i <= 9; i++) {
		ans += dp[n][i];
		ans %= mod;
	}
	cout << ans;
	return 0;
}	