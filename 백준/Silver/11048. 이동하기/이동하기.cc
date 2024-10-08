#include <bits/stdc++.h>

#define PII pair<int,int>
using namespace std;
typedef long long ll;

int N, M;
int arr[1001][1001], dp[1001][1001];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) cin >> arr[i][j];
	dp[0][0] = arr[0][0];
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (i > 0) dp[i][j] = max(dp[i][j], dp[i - 1][j] + arr[i][j]);
			if (j > 0) dp[i][j] = max(dp[i][j], dp[i][j - 1] + arr[i][j]);
			if (i>0 && j>0) dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + arr[i][j]);
		}
	}
	cout << dp[N - 1][M - 1];
	
	return 0;
}