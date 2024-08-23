#include <bits/stdc++.h>

#define PII pair<int,int>
#define PIII pair<int,PII>

using namespace std;
typedef long long ll;

int dx[] = { 0,-1,1,0,0 };
int dy[] = { 0,0,0,1,-1 };
int R, C, M, ans = 0;

typedef struct Shark {
	int speed;
	int dir;
	int size;
	bool isMoved;
} Shark;

vector<Shark> board[101][101];

bool cmp(Shark& a, Shark& b) {
	return a.size < b.size;
}

void fishing(int colNum) {
	for (int i = 0; i < R; i++) {
		if (!board[i][colNum].empty()) {
			ans += board[i][colNum][0].size;
			board[i][colNum].clear();
			break;
		}
	}
}

void moveSharks() {
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (board[i][j].empty()) continue;

			for (int k = 0; k < board[i][j].size(); k++) {
				if (board[i][j][k].isMoved) continue;

				int speed = board[i][j][k].speed;
				int dir = board[i][j][k].dir;

				if (dir == 1 || dir == 2) {
					speed %= (R - 1) * 2;
					if (speed == 0) continue;

					int x = i;
					int y = j;
					while (speed--) {
						if (x == 0 && dir == 1) dir = 2;
						else if (x == R - 1 && dir == 2) dir = 1;

						x += dx[dir];
						y += dy[dir];
					}
					board[x][y].push_back({ board[i][j][k].speed, dir, board[i][j][k].size, true });
					board[i][j].erase(board[i][j].begin() + k);
					k--;
				}
				else {
					speed %= (C - 1) * 2;
					if (speed == 0) continue;

					int x = i;
					int y = j;
					while (speed--) {
						if (y == 0 && dir == 4) dir = 3;
						else if (y == C - 1 && dir == 3) dir = 4;

						x += dx[dir];
						y += dy[dir];
					}
					board[x][y].push_back({ board[i][j][k].speed, dir, board[i][j][k].size, true });
					board[i][j].erase(board[i][j].begin() + k);
					k--;
				}
			}
		}
	}
}

void eat() {
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (board[i][j].size() > 1) {
				sort(board[i][j].begin(), board[i][j].end(), cmp);
				Shark shk = board[i][j].back();
				board[i][j].clear();
				board[i][j].push_back(shk);
			}
		}
	}
}

void setStatus() {
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (!board[i][j].empty()) {
				for (int k = 0; k < board[i][j].size(); k++) {
					board[i][j][k].isMoved = false;
				}
			}
		}
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> R >> C >> M;

	int r, c, s, d, z;
	for (int i = 0; i < M; i++) {
		cin >> r >> c >> s >> d >> z;
		board[r - 1][c - 1].push_back({ s, d, z, false });
	}

	for (int i = 0; i < C; i++) {
		fishing(i);
		moveSharks();
		eat();
		setStatus();
	}

	cout << ans;
	return 0;
}