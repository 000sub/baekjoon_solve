#include <bits/stdc++.h>

#define PII pair<int,int>
#define PIII pair<int,PII>
using namespace std;
typedef long long ll;

int N,M,K;
int dp[50][901];
ll D[50], P[14];
int Q[14];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M >> K;
	for (int i = 0; i < N; i++) cin >> D[i];
	for (int i = 0; i < K; i++) cin >> P[i] >> Q[i];
	sort(D, D + N, greater<>());

	for (int i = 0; i < M; i++) {
		ll damage = D[i];
		for (int k = 0; k < K; k++) {
			ll health = P[k];
			int value = Q[k];

			ll cost = health / damage;
			if (health % damage) cost++;

			for (int j = 900; j >= 0; j--) {
				if (j >= cost) dp[i][j] = max(dp[i][j], dp[i][j - cost] + value);
			}
		}
	}

	int ans = 0;

	for (int i = 0; i < M; i++) {
		int val = 0;
		for (int j = 0; j <= 900; j++) {
			val = max(val, dp[i][j]);
		}
		ans += val;
	}

	cout << ans;
	return 0;
}