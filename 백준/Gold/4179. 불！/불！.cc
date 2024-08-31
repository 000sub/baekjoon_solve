#include <bits/stdc++.h>
#define PII pair<int,int>
#define PIII pair<int,PII>

using namespace std;
typedef long long ll;
const int INF = 1e9;

int R, C;
char arr[1001][1001];
int fire[1001][1001];
bool visited[1001][1001];
int jx, jy;
int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1 };
vector<PII> initFires;

void fire_simulation() {
	queue<PIII> q;
	memset(visited, false, sizeof(visited));
	for (PII p : initFires) {
		q.push({ 0, p });
		visited[p.first][p.second] = true;
	}
	for (int i = 0; i < R; i++) for (int j = 0; j < C; j++) fire[i][j] = INF;

	while (!q.empty()) {
		int time = q.front().first;
		int cx = q.front().second.first;
		int cy = q.front().second.second;
		q.pop();

		fire[cx][cy] = min(fire[cx][cy], time);

		for (int d = 0; d < 4; d++) {
			int nx = cx + dx[d];
			int ny = cy + dy[d];

			if (nx<0 || ny<0 || nx>R - 1 || ny>C - 1 || visited[nx][ny] || arr[nx][ny] == '#') continue;

			visited[nx][ny] = true;
			q.push({ time + 1, {nx, ny} });
		}
	}
}

void simulation(int x, int y) {
	queue<PIII> q;
	memset(visited, false, sizeof(visited));
	q.push({ 0, {x,y} });
	visited[x][y] = true;

	while (!q.empty()) {
		int time = q.front().first;
		int cx = q.front().second.first;
		int cy = q.front().second.second;
		q.pop();

		if (cx == 0 || cy == 0 || cx == R - 1 || cy == C - 1) {
			cout << time + 1;
			exit(0);
		}

		for (int d = 0; d < 4; d++) {
			int nx = cx + dx[d];
			int ny = cy + dy[d];

			if (nx<0 || ny<0 || nx>R - 1 || ny>C - 1 || visited[nx][ny] || arr[nx][ny] == '#' || time + 1 >= fire[nx][ny]) continue;

			visited[nx][ny] = true;
			q.push({ time + 1, {nx, ny} });
		}
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 'J') jx = i, jy = j;
			else if (arr[i][j] == 'F') initFires.emplace_back(i, j);
		}
	}

	fire_simulation();
	simulation(jx, jy);

	cout << "IMPOSSIBLE";

	return 0;


}