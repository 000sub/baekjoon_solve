#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <cstring>
#define PII pair<int,int>

using namespace std;
typedef long long ll;
int board[101][101];
bool visited[101][101];
int n, maxH = 0, ans = 0;
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };

void BFS(int h, int x, int y) {
	queue<PII> q;
	q.push({ x,y });
	visited[x][y] = true;

	while (!q.empty()) {
		int cx = q.front().first;
		int cy = q.front().second;
		q.pop();

		for (int d = 0; d < 4; d++) {
			int nx = cx + dx[d];
			int ny = cy + dy[d];

			if (nx<0 || ny<0 || nx>n - 1 || ny>n - 1 || visited[nx][ny] || board[nx][ny] <= h) continue;
			q.push({ nx, ny });
			visited[nx][ny] = true;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
			maxH = max(maxH, board[i][j]);
		}
	}

	for (int i = 0; i < maxH; i++) {
		int cnt = 0;
		memset(visited, false, sizeof(visited));
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				if (board[j][k] > i && !visited[j][k]) {
					BFS(i, j, k);
					cnt++;
				}
			}
		}
		ans = max(ans, cnt);
	}

	cout << ans;

	return 0;
}