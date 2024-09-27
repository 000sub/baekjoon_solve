#include <bits/stdc++.h>

#define PII pair<int,int>
#define PIII pair<int,PII>
using namespace std;
typedef long long ll;

int N, M, T;
int arr[101][101];
bool visited[101][101][2];
int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };
struct Node {
	int x;
	int y;
	int time;
	int canBreak;
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M >> T;
	for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) cin >> arr[i][j];

	queue<Node> q;
	q.push({ 0,0,0,0 });
	visited[0][0][0] = true;
	while (!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		int time = q.front().time;
		int canBreak = q.front().canBreak;
		q.pop();

		if (x == N - 1 && y == M - 1) {
			cout << time;
			return 0;
		}
		if (time > T) continue;

		if (arr[x][y] == 2) canBreak = 1;

		for (int d = 0; d < 4; d++) {
			int nx = x + dx[d];
			int ny = y + dy[d];

			if (nx < 0 || ny < 0 || nx >= N || ny >= M || visited[nx][ny][canBreak]) continue;
			if (!canBreak && arr[nx][ny] == 1) continue;

			q.push({ nx, ny, time + 1, canBreak });
			visited[nx][ny][canBreak] = true;
		}
	}

	cout << "Fail";
	return 0;
}