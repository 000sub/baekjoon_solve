#include <bits/stdc++.h>

#define PII pair<int,int>
using namespace std;
typedef long long ll;

int N, M, ans = 0;
bool isLand[51][51], visited[51][51];
int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };

struct QNode {
	int x;
	int y;
	int cnt;
};

void bfs(int sx, int sy) {
	memset(visited, false, sizeof(visited));
	queue<QNode> q;
	visited[sx][sy] = true;
	q.push({ sx, sy, 0 });
	while (!q.empty()) {
		auto [x, y, cnt] = q.front();
		q.pop();

		ans = max(ans, cnt);

		for (int d = 0; d < 4; d++) {
			int nx = x + dx[d];
			int ny = y + dy[d];
			if (nx < 0 || ny < 0 || nx >= N || ny >= M || !isLand[nx][ny] || visited[nx][ny]) continue;

			visited[nx][ny] = true;
			q.push({ nx, ny, cnt + 1 });
		}
	}

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M;
	char ch;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> ch;
			isLand[i][j] = ch == 'L';
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (isLand[i][j]) bfs(i, j);
		}
	}

	cout << ans;
	return 0;
}