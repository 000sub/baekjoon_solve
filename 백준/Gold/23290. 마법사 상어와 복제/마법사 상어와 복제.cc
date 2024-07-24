#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#define PII pair<int,int>

using namespace std;
typedef long long ll;
typedef struct fish {
	int x;
	int y;
	int dir;
} Fish;

int dx[] = { 0,-1,-1,-1,0,1,1,1 };
int dy[] = { -1,-1,0,1,1,1,0,-1 };
int sdx[] = {-1,0,1,0};
int sdy[] = {0,-1,0,1};
vector<Fish> board[4][4], tempBoard[4][4];
int smell_time[4][4];
int tempPath[3], path[3];
int maxFishCnt;
PII shark;
int m, s, fx, fy, d, sx, sy;
bool v[4][4];

void duplicate_fishes() {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			tempBoard[i][j] = board[i][j];
		}
	}
}

void move_fishes() {
	vector<Fish> tempBoard2[4][4];

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			for (int k = 0; k < board[i][j].size(); k++) {
				int x = board[i][j][k].x;
				int y = board[i][j][k].y;
				int dir = board[i][j][k].dir;
				dir++;
				bool flag = false;
				for (int d = 0; d <= 8; d++) {
					dir = (dir + 7) % 8;
					int nx = x + dx[dir];
					int ny = y + dy[dir];

					if (nx < 0 || ny < 0 || nx>3 || ny>3) continue;
					if (shark.first == nx && shark.second == ny) continue;
					if (smell_time[nx][ny] > 0) continue;

					flag = true;
					tempBoard2[nx][ny].push_back({nx, ny, dir});
					break;
				}

				if (!flag) tempBoard2[x][y].push_back({ x, y, dir });
			}
		}
	}

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			board[i][j] = tempBoard2[i][j];
		}
	}
}

int getCurFish() {
	memset(v, false, sizeof(v));
	int cnt = 0;

	int nx = shark.first;
	int ny = shark.second;

	for (int i = 0; i < 3; i++) {
		nx += sdx[tempPath[i]];
		ny += sdy[tempPath[i]];

		if (nx < 0 || ny < 0 || nx>3 || ny>3) return -1;

		if (!v[nx][ny]) {
			cnt += board[nx][ny].size();
			v[nx][ny] = true;
		}
	}

	return cnt;
}

void BT(int cnt) {
	if (cnt == 3) {
		int curFishCnt = getCurFish();
		if (curFishCnt > maxFishCnt) {
			maxFishCnt = curFishCnt;
			for (int i = 0; i < 3; i++) {
				path[i] = tempPath[i];
			}
		}
		return;
	}

	for (int i = 0; i < 4; i++) {
		tempPath[cnt] = i;
		BT(cnt + 1);
	}
}

void move_shark() {
	maxFishCnt = -1;
	
	BT(0);

	int nx = shark.first;
	int ny = shark.second;

	for (int i = 0; i < 3; i++) {
		nx += sdx[path[i]];
		ny += sdy[path[i]];

		if (board[nx][ny].size() > 0) {
			smell_time[nx][ny] = 3;
			board[nx][ny].clear();
		}
	}

	shark.first = nx;
	shark.second = ny;
}

void renew_smell() {
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			if (smell_time[i][j] > 0)
				smell_time[i][j]--;
}

void load_temp_fishes() {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			for (Fish f : tempBoard[i][j]) {
				board[i][j].push_back(f);
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> m >> s;
	for (int i = 0; i < m; i++) {
		cin >> fx >> fy >> d;
		board[fx - 1][fy - 1].push_back({ fx - 1, fy - 1, (d + 7) % 8 });
	}
	cin >> sx >> sy;
	shark = { sx - 1, sy - 1 };

	while (s--) {
		duplicate_fishes();
		move_fishes();
		move_shark();
		renew_smell();
		load_temp_fishes();
	}

	int ans = 0;
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			ans += board[i][j].size();

	cout << ans;
	return 0;
}