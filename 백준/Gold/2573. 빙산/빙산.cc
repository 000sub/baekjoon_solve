#include <bits/stdc++.h>

#define PII pair<int,int>
using namespace std;
typedef long long ll;

int N, M;
int arr[301][301], temp[301][301];

constexpr int dx[] = { 1,0,-1,0 };
constexpr int dy[] = { 0,1,0,-1 };
bool visited[301][301];

void melt() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (arr[i][j] > 0) {
				int cnt = 0;
				for (int d = 0; d < 4; d++) {
					int nx = i + dx[d];
					int ny = j + dy[d];
					if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
					if (arr[nx][ny] == 0) cnt++;
				}
				temp[i][j] = cnt;
			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (arr[i][j] > 0) arr[i][j] = max(0, arr[i][j] - temp[i][j]);
		}
	}
}

void bfs(int x, int y) {
	queue<PII> q;
	q.push({ x, y });
	visited[x][y] = true;

	while (!q.empty()) {
		auto [cx, cy] = q.front();
		q.pop();

		for (int d = 0; d < 4; d++) {
			int nx = cx + dx[d];
			int ny = cy + dy[d];
			if (nx < 0 || ny < 0 || nx >= N || ny >= M || visited[nx][ny] || arr[nx][ny] == 0) continue;
			q.push({ nx, ny });
			visited[nx][ny] = true;
		}
	}
}

int check() {
	bool hasOne = false;
	memset(visited, false, sizeof(visited));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (!hasOne && !visited[i][j] && arr[i][j] > 0) hasOne = true, bfs(i, j);
			else if (hasOne && !visited[i][j] && arr[i][j] > 0) return 0;
		}
	}

	if (!hasOne) return -1;
	return 1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) cin >> arr[i][j];

	int time = 0;
	while (true) {
		time++;
		melt();
		int status = check();
		if (status == -1) {
			cout << 0;
			return 0;
		}
		else if (status == 0) break;
	}
	cout << time;
	return 0;
}