#include <bits/stdc++.h>

#define PII pair<int,int>
#define PIII pair<int,PII>
using namespace std;
typedef long long ll;

int N, M;
char arr[11][11];
bool visited[11][11][11][11];
PII RED, BLUE, GOAL;
int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };

struct Node {
	int rx;
	int ry;
	int bx;
	int by;
	int cnt;
};

int BFS() {	
	queue<Node> q;
	visited[RED.first][RED.second][BLUE.first][BLUE.second] = true;
	q.push({ RED.first, RED.second, BLUE.first, BLUE.second, 0 });

	while (!q.empty()) {
		int rx = q.front().rx;
		int ry = q.front().ry;
		int bx = q.front().bx;
		int by = q.front().by;
		int cnt = q.front().cnt;
		q.pop();

		if (cnt > 10) continue;
		if (rx == GOAL.first && ry == GOAL.second) {
			return cnt;
		}
		for (int d = 0; d < 4; d++) {
			int nrx = rx;
			int nry = ry;
			int nbx = bx;
			int nby = by;
			int rCnt = 0, bCnt = 0;

			while (arr[nrx][nry] != '#' && arr[nrx][nry] != 'O') {
				nrx += dx[d];
				nry += dy[d];
				rCnt++;
			}
			if (arr[nrx][nry] == '#') {
				nrx -= dx[d];
				nry -= dy[d];
				rCnt--;
			}

			
			while (arr[nbx][nby] != '#' && arr[nbx][nby] != 'O') {
				nbx += dx[d];
				nby += dy[d];
				bCnt++;
			}
			if (arr[nbx][nby] == '#') {
				nbx -= dx[d];
				nby -= dy[d];
				bCnt--;
			}

			if (nbx == GOAL.first && nby == GOAL.second) continue;
			if (nrx == nbx && nry == nby) {
				if (rCnt > bCnt) {
					nrx -= dx[d];
					nry -= dy[d];
				}
				else {
					nbx -= dx[d];
					nby -= dy[d];
				}
			}

			if (visited[nrx][nry][nbx][nby]) continue;

			q.push({ nrx, nry, nbx, nby, cnt + 1 });
			visited[nrx][nry][nbx][nby] = true;
		}
	}

	return -1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 'B') BLUE = { i,j };
			else if (arr[i][j] == 'R') RED = { i,j };
			else if (arr[i][j] == 'O') GOAL = { i, j };
		}
	}

	cout<<BFS();
	return 0;
}