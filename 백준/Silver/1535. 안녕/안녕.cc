#include <bits/stdc++.h>

#define PII pair<int,int>
#define PIII pair<int,PII>
using namespace std;
typedef long long ll;

int N;
int dp[21][100];
int cost[21], value[21];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) cin >> cost[i];
	for (int i = 0; i < N; i++) cin >> value[i];

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 100; j++) {
			if (j >= cost[i]) dp[i + 1][j] = max(dp[i][j], dp[i][j - cost[i]] + value[i]);
			else dp[i + 1][j] = dp[i][j];
		}
	}

	cout << dp[N][99];
	return 0;
}