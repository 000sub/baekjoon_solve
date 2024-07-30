#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <unordered_map>
#include <set>
#include <queue>
#include <stack>
#define PII pair<int,int>

using namespace std;
typedef long long ll;

int n, m, ans = 0, x1, Y1, x2, y2;
char board[301][301];
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
bool visited[301][301];
bool flag = false;

void BFS(int x, int y) {
	queue<PII> q;
	memset(visited, false, sizeof(visited));
	q.push({ x,y });
	visited[x][y] = true;

	while (!q.empty()) {
		int cx = q.front().first;
		int cy = q.front().second;
		q.pop();

		for (int d = 0; d < 4; d++) {
			int nx = cx + dx[d];
			int ny = cy + dy[d];

			if (nx<0 || ny<0 || nx>n - 1 || ny>m - 1) continue;

			while (board[nx][ny] == '0' && !visited[nx][ny]) {
				if (nx<0 || ny<0 || nx>n - 1 || ny>m - 1) break;
				q.push({ nx,ny });
				visited[nx][ny] = true;
				nx += dx[d];
				ny += dy[d];
			}

			if (board[nx][ny] == '#') {
				flag = true;
				return;
			}

			if (board[nx][ny] == '1') board[nx][ny] = '2';
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (board[i][j] == '2') board[i][j] = '0';
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;
	cin >> x1 >> Y1 >> x2 >> y2;
	x1--; Y1--; x2--; y2--;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
		}
	}
	
	while (!flag) {
		BFS(x1, Y1);
		ans++;
	}

	cout << ans;

	return 0;
}