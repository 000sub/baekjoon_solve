#include <iostream>
#include <algorithm>
#include <queue>

#define PII pair<int,int>
using namespace std;

int board[101][101];
int cnt = 0;
vector<int> sizes;
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
int m, n, k;

void BFS(int x, int y) {
	int size = 0;
	queue<PII> q;
	q.push({ x,y });
	while (!q.empty()) {
		int cx = q.front().first;
		int cy = q.front().second;
		q.pop();
		if (board[cx][cy]) continue;
		board[cx][cy] = 1;
		size++;

		for (int d = 0; d < 4; d++) {
			int nx = cx + dx[d];
			int ny = cy + dy[d];

			if (nx<0 || ny<0 || nx>m - 1 || ny>n - 1 || board[nx][ny]) continue;
			q.push({ nx, ny });
		}
	}

	sizes.push_back(size);
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	
	cin >> m >> n >> k;

	int x1, x2, y1, y2;
	for (int i = 0; i < k; i++) {
		cin >> y1 >> x1 >> y2 >> x2;
		for (int j = m-x2; j < m-x1; j++)
			for (int l = y1; l < y2; l++)
				board[j][l] = 1;
	}

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (board[i][j] == 0) {
				cnt++;
				BFS(i, j);
			}
		}
	}

	sort(sizes.begin(), sizes.end());

	cout << cnt << '\n';
	for (int i : sizes) cout << i << ' ';
	cout << '\n';

	return 0;
}