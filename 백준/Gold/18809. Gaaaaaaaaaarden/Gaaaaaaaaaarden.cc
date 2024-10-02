#include <bits/stdc++.h>

#define PII pair<int,int>
using namespace std;
typedef long long ll;

int N, M, G, R, ans = 0;
int arr[51][51], red[51][51], green[51][51], temp[51][51];
vector<PII> canPlants;
bool isGreen[11], isRed[11];
constexpr int INF = 1e9;
constexpr int dx[] = { 1,0,-1,0 };
constexpr int dy[] = { 0,1,0,-1 };

struct QNode {
	int x;
	int y;
	int cnt;
};

void bfs() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			red[i][j] = INF;
			green[i][j] = INF;
			temp[i][j] = arr[i][j];
		}
	}

	int total = 0;

	queue<QNode> redQ, greenQ;
	for (int i = 0; i < canPlants.size(); i++) {
		if (isGreen[i]) {
			greenQ.push({ canPlants[i].first, canPlants[i].second, 0 });
			green[canPlants[i].first][canPlants[i].second] = 0;
			temp[canPlants[i].first][canPlants[i].second] = 3; //Green 3
		}
		if (isRed[i]) {
			redQ.push({ canPlants[i].first, canPlants[i].second, 0 });
			red[canPlants[i].first][canPlants[i].second] = 0;
			temp[canPlants[i].first][canPlants[i].second] = 4; //Red 4
		}
	}

	while (!greenQ.empty() || !redQ.empty()) {
		int gSize = greenQ.size();
		int rSize = redQ.size();

		for (int i = 0; i < gSize; i++) {
			auto [x, y, cnt] = greenQ.front();
			greenQ.pop();
			//꽃이 이미 있음
			if (temp[x][y] == -1) continue;

			for (int d = 0; d < 4; d++) {
				int nx = x + dx[d];
				int ny = y + dy[d];
				if (nx < 0 || ny < 0 || nx >= N || ny >= M || green[nx][ny] < cnt+1) continue;
				if (temp[nx][ny] == 1 || temp[nx][ny] == 2) {
					green[nx][ny] = cnt + 1;
					greenQ.push({ nx, ny, cnt + 1 });
					temp[nx][ny] = 3;
				}

			}
		}

		for (int i = 0; i < rSize; i++) {
			auto [x, y, cnt] = redQ.front();
			redQ.pop();
			//꽃이 이미 있음
			if (temp[x][y] == -1) continue;

			for (int d = 0; d < 4; d++) {
				int nx = x + dx[d];
				int ny = y + dy[d];
				if (nx < 0 || ny < 0 || nx >= N || ny >= M || red[nx][ny] < cnt + 1) continue;
				if (temp[nx][ny] == 1 || temp[nx][ny] == 2) {
					red[nx][ny] = cnt + 1;
					redQ.push({ nx, ny, cnt + 1 });
					temp[nx][ny] = 4;
				}
				//꽃 발견
				else if (temp[nx][ny] == 3 && green[nx][ny] == cnt + 1) {
					red[nx][ny] = cnt + 1;
					temp[nx][ny] = -1;
					total++;
				}
			}
		}
	}

	ans = max(ans, total);
}

void dfs(int idx, int gCnt, int rCnt) {
	if (gCnt == G && rCnt == R) {
		bfs();
		return;
	}

	if (gCnt > G || rCnt > R) return;
	if (idx == canPlants.size()) return;

	isGreen[idx] = true;
	dfs(idx + 1, gCnt+1, rCnt);
	isGreen[idx] = false;

	isRed[idx] = true;
	dfs(idx + 1, gCnt, rCnt + 1);
	isRed[idx] = false;

	dfs(idx + 1, gCnt, rCnt);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M >> G >> R;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 2) canPlants.push_back({ i, j });
		}
	}

	dfs(0, 0, 0);

	cout << ans;
	return 0;
}