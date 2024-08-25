#include <bits/stdc++.h>
#define PII pair<int,int>
#define PIII pair<int,PII>

using namespace std;
typedef long long ll;
const int INF = 1e9;

int N, M, ans = INF;
int arr[51][51];
bool visited[51][51];
vector<PII> virus, cur;
int dx[] = { 0,1,0,-1 };
int dy[] = { -1,0,1,0 };

bool isFinished() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (arr[i][j] == 0 && !visited[i][j]) return false;
		}
	}

	return true;
}

void simulate() {
	int time = 0;
	memset(visited, false, sizeof(visited));

	queue<PIII> q;
	for (PII p : cur) {
		q.push({0, p });
		visited[p.first][p.second] = true;
	}

	while (!q.empty()) {
		int curTime = q.front().first;
		int x = q.front().second.first;
		int y = q.front().second.second;
		q.pop();

		if (arr[x][y] != 2 ) time = max(curTime, time);

		for (int d = 0; d < 4; d++) {
			int nx = x + dx[d];
			int ny = y + dy[d];

			if (nx<0 || ny<0 || nx>N - 1 || ny>N - 1 || arr[nx][ny] == 1 || visited[nx][ny]) continue;

			visited[nx][ny] = true;
			if (arr[nx][ny] == 2) q.push(PIII(curTime+1, { nx, ny }));
			else q.push(PIII(curTime+1, { nx, ny }));
		}
	}

	if (isFinished()) ans = min(ans, time);
}

void bt(int idx, int cnt) {
	if (cnt == M) {
		simulate();
		return;
	}

	for (int i = idx; i < virus.size(); i++) {
		cur.push_back(virus[i]);
		bt(i + 1, cnt+1);
		cur.pop_back();
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 2) {
				virus.push_back({ i, j });
			}
		}
	}

	bt(0, 0);
	ans == INF ? cout << -1 : cout << ans;
	return 0;
}