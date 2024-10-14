#include <bits/stdc++.h>

#define PII pair<int,int>
using namespace std;
typedef long long ll;

const int INF = 1e9;
int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };

int T, W, H;
int sx, sy;
char arr[1001][1001];
bool visited[1001][1001];
int fire[1001][1001];
vector<PII> fire_pos;

struct QNode {
	int x;
	int y;
	int cnt;
};

void calcDist() {
	queue<QNode> q;
	memset(visited, false, sizeof(visited));

	for (PII& p : fire_pos) {
		q.push({ p.first, p.second, 0 });
		visited[p.first][p.second] = true;
	}

	while (!q.empty()) {
		auto [x, y, cnt] = q.front();
		q.pop();

		if (fire[x][y] < cnt) continue;
		fire[x][y] = cnt;

		for (int d = 0; d < 4; d++) {
			int nx = x + dx[d];
			int ny = y + dy[d];
			if (nx < 0 || ny < 0 || nx >= H || ny >= W || visited[nx][ny] || fire[nx][ny] <= cnt + 1 || arr[nx][ny] == '#') continue;
			visited[nx][ny] = true;
			q.push({ nx, ny, cnt + 1 });
		}
	}
}

int bfs() {
	queue<QNode> q;
	memset(visited, false, sizeof(visited));
	visited[sx][sy] = true;
	q.push({ sx, sy, 0 });

	while (!q.empty()) {
		auto [x, y, cnt] = q.front();
		q.pop();

		for (int d = 0; d < 4; d++) {
			int nx = x + dx[d];
			int ny = y + dy[d];
			if (nx < 0 || ny < 0 || nx >= H || ny >= W) return cnt + 1;
			if (visited[nx][ny] || fire[nx][ny] <= cnt + 1 || arr[nx][ny] != '.') continue;
			visited[nx][ny] = true;
			q.push({ nx, ny, cnt + 1 });
		}
	}
	return -1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> T;
	while (T--) {
		fire_pos.clear();
		cin >> W >> H;
		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++) {
				cin >> arr[i][j];
				fire[i][j] = INF;
				if (arr[i][j] == '*') {
					fire_pos.push_back({ i, j });
				}
				else if (arr[i][j] == '@') sx = i, sy = j;
			}
		}

		calcDist();
		int res = bfs();

		res == -1 ? cout << "IMPOSSIBLE" : cout << res;
		cout << '\n';
	}
	return 0;
}