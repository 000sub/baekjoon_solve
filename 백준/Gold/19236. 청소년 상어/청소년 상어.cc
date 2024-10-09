#include <bits/stdc++.h>

#define PII pair<int,int>
using namespace std;
typedef long long ll;

struct Fish {
	int idx;
	int dir;
};

int dx[] = {-1,-1,0,1,1,1,0,-1};
int dy[] = {0,-1,-1,-1,0,1,1,1};

Fish arr[4][4];
int ans = 0;

void copyArr(Fish src[4][4], Fish dst[4][4]) {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			dst[i][j] = src[i][j];
		}
	}
}

void moveFishes(int sx, int sy, Fish fishMap[4][4]) {
	for (int k = 1; k <= 16; k++) {
		bool moved = false;
		for (int i = 0; i < 4; i++) {
			if (moved) break;
			for (int j = 0; j < 4; j++) {
				if (moved) break;

				if (fishMap[i][j].idx == k) {
					moved = true;
					int nDir = fishMap[i][j].dir;
					int nx = i + dx[nDir];
					int ny = j + dy[nDir];
					if (nx>=0 && ny>=0 && nx<4 && ny<4 && (nx != sx || ny != sy)) {
						if (fishMap[nx][ny].idx == 0) {
							fishMap[nx][ny] = fishMap[i][j];
							fishMap[i][j] = { 0,0 };
							continue;
						}
						else if (fishMap[nx][ny].idx > 0) {
							Fish temp = fishMap[nx][ny];
							fishMap[nx][ny] = fishMap[i][j];
							fishMap[i][j] = temp;
							continue;
						}
					}
					
					for (int d = 0; d < 7; d++) {
						nDir = (nDir + 1) % 8;
						nx = i + dx[nDir];
						ny = j + dy[nDir];
						if (nx >= 0 && ny >= 0 && nx < 4 && ny < 4 && (nx != sx || ny != sy)) {
							if (fishMap[nx][ny].idx == 0) {
								fishMap[nx][ny] = { fishMap[i][j].idx, nDir };
								fishMap[i][j] = { 0,0 };
								break;
							}
							else if (fishMap[nx][ny].idx > 0) {
								Fish temp = fishMap[nx][ny];
								fishMap[nx][ny] = { fishMap[i][j].idx, nDir };
								fishMap[i][j] = temp;
								break;
							}
						}
					}
				}
			}
		}
	}
}

void dfs(int sx, int sy, int sDir, int score, Fish temp[4][4]) {
	//상어가 해당 위치 먹음
	score += temp[sx][sy].idx;
	sDir = temp[sx][sy].dir;

	Fish temp2[4][4];
	copyArr(temp, temp2);
	temp2[sx][sy] = { 0,0 };
	moveFishes(sx, sy, temp2);

	//다음 경로 탐색

	for (int i = 1; i <= 3; i++) {
		int nx = sx + i * dx[sDir];
		int ny = sy + i * dy[sDir];
		if (temp2[nx][ny].idx == 0) continue;
		if (nx < 0 || ny < 0 || nx >= 4 || ny >= 4) break;
		dfs(nx, ny, sDir, score, temp2);
	}

	//score를 비교
	ans = max(ans, score);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			cin >> arr[i][j].idx >> arr[i][j].dir;
			arr[i][j].dir--;
		}
	}
	
	dfs(0, 0, -1, 0, arr);
	cout << ans;
	return 0;
}