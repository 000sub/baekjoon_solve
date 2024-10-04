#include <bits/stdc++.h>

#define PII pair<int,int>
using namespace std;

int N, M, sx, sy, ex, ey;
char arr[51][51];
bool visited[51][51][1<<5];
vector<PII> v;

int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };

struct QNode {
	int x;
	int y;
	int cnt;
	int state;
};

int getItemIdx(int x, int y) {
	for (int i = 0; i < v.size(); i++) {
		if (v[i].first == x && v[i].second == y) return i;
	}

	return -1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 'X') {
				v.push_back({ i, j });
			}
			else if (arr[i][j] == 'S') {
				sx = i, sy = j;
			}
			else if (arr[i][j] == 'E') {
				ex = i, ey = j;
			}
		}
	}

	queue<QNode> q;
	q.push({ sx, sy, 0, 0 });
	while (!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		int cnt = q.front().cnt;
		int state = q.front().state;
		q.pop();

		if (ex==x && ey==y && state == (1 << v.size()) - 1) {
			cout << cnt;
			return 0;
		}

		for (int d = 0; d < 4; d++) {
			int nx = x + dx[d];
			int ny = y + dy[d];

			if (nx < 0 || ny < 0 || nx >= M || ny >= N || arr[nx][ny] == '#' || visited[nx][ny][state]) continue;
			
			if (arr[nx][ny] == 'X') {
				int idx = getItemIdx(nx, ny);
				visited[nx][ny][state | (1 << idx)] = true;
				q.push({ nx, ny, cnt + 1, state | (1 << idx) });
			}
			else {
				visited[nx][ny][state] = true;
				q.push({ nx, ny, cnt + 1, state });
			}
		}
	}

	return 0;
}