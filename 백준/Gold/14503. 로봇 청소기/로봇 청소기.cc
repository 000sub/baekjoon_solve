#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#define PII pair<int,int>

using namespace std;
typedef long long ll;

int board[51][51];
int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};
int rx, ry, rdir, cnt = 0;
int n, m;

void tryClean() {
	if (board[rx][ry] == 0) {
		cnt++;
		board[rx][ry] = 2;
	}
}

bool move() {
	for (int d = 0; d < 4; d++) {
		int ndir = (rdir + 3 * (d+1)) % 4;
		int nx = rx + dx[ndir];
		int ny = ry + dy[ndir];

		if (nx<0 || ny<0 || nx>n - 1 || ny>m - 1 || board[nx][ny] != 0) continue;

		rx = nx;
		ry = ny;
		rdir = ndir;
		return true;
	}

	if (board[rx - dx[rdir]][ry - dy[rdir]] != 1) {
		rx -= dx[rdir];
		ry -= dy[rdir];
		return true;
	}

	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	
	cin >> n >> m;
	cin >> rx >> ry >> rdir;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> board[i][j];

	while (1) {
		tryClean();
		if (move() == false) break;
	}

	cout << cnt;

	return 0;
}