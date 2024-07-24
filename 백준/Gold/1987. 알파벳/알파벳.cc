#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define PII pair<int,int>

using namespace std;
typedef long long ll;

int r, c;
char board[21][21];
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };
int ans = 0;
bool visited(unsigned state, char c) {
	return (1 << c - 'A') & state;
}

void DFS(PII pos, int cnt, unsigned state) {
	int x = pos.first;
	int y = pos.second;
	ans = max(cnt, ans);
	
	for (int d = 0; d < 4; d++) {
		int nx = x + dx[d];
		int ny = y + dy[d];
		if (nx<0 || ny<0 || nx>r - 1 || ny>c - 1 || visited(state, board[nx][ny])) continue;
		DFS({ nx, ny }, cnt + 1, state | (1 << (board[nx][ny] - 'A')));
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> r >> c;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> board[i][j];
		}
	}

	unsigned init_state = 1 << (board[0][0] - 'A');
	
	DFS({ 0,0 }, 1, init_state);

	cout << ans;

	return 0;
}