#include <bits/stdc++.h>
#define PII pair<int,int>
#define PIII pair<int,PII>

using namespace std;
typedef long long ll;
const int INF = 1e9;

int N, M;
int m[101], c[101], dp[101][10001];


int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> N >> M;
	for (int i = 0; i < N; i++) cin >> m[i];
	for (int i = 0; i < N; i++) cin >> c[i];

	for (int i = 0; i < N; i++) {
		int mem = m[i];
		int cost = c[i];

		//dp[c] = c 비용에서의 최대 메모리 절약
		for (int j = 0; j <= 10000; j++) {
			if (j >= cost) dp[i + 1][j] = max(dp[i][j], dp[i][j - cost] + mem);
			else dp[i + 1][j] = dp[i][j];
		}
	}

	int ans = lower_bound(dp[N], dp[N] + 10001, M) - dp[N];
	cout << ans;
	return 0;
}