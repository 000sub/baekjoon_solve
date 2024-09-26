#include <bits/stdc++.h>

#define PII pair<int,int>
#define PIII pair<int,PII>
using namespace std;
typedef long long ll;
int N;
int arr[101][101];
ll dp[101][101];

int dx[] = { 0, 1 };
int dy[] = { 1,0 };

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	dp[0][0] = 1;
	for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) cin >> arr[i][j];
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (arr[i][j] == 0) continue;
			for (int d = 0; d < 2; d++) {
				int nx = i + dx[d] * arr[i][j];
				int ny = j + dy[d] * arr[i][j];
				if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
				dp[nx][ny] += dp[i][j];
			}
		}
	}
	cout << dp[N - 1][N - 1];
	return 0;
}