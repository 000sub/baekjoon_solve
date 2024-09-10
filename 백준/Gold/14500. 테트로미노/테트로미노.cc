#include <bits/stdc++.h>
#define PII pair<int, int>

using namespace std;

int N, M, ans = 0;
int arr[501][501];
bool visited[501][501];
vector<PII> v;
int dx[] = { 0,1,0,-1 };
int dy[] = { 1,0,-1,0 };

void check() {
	int sum = 0;
	for (PII& p : v) sum += arr[p.first][p.second];
	ans = max(ans, sum);
}

void DFS() {
	if (v.size() == 4) {
		check();
		return;
	}

	for (PII& p : v) {
		int x = p.first;
		int y = p.second;
		for (int d = 0; d < 4; d++) {
			int nx = x + dx[d];
			int ny = y + dy[d];

			if (nx < 0 || ny < 0 || nx >= N || ny >= M || visited[nx][ny]) continue;

			v.push_back({ nx, ny });
			visited[nx][ny] = true;
			DFS();
			visited[nx][ny] = false;
			v.pop_back();
		}
	}
	
}

int main() {
	ios::sync_with_stdio;
	cin.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			visited[i][j] = true;
			v.push_back({ i, j });
			DFS();
			v.pop_back();
			visited[i][j] = false;
		}
	}
	cout << ans;
	return 0;
}