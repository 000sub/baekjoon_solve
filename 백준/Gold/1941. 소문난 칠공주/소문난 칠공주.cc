#include <iostream>
#include <vector>
#include <cstring>
#include <queue>

#define PII pair<int,int>
using namespace std;

int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};
int ans = 0;
bool arr[5][5], mark[5][5], visited[5][5];

int bfs(int x, int y) {
	int cnt = 0;
	queue<PII> q;
	visited[x][y] = true;
	q.push({x, y});

	while (!q.empty()) {
		auto [cx, cy] = q.front();
		q.pop();

		cnt++;

		for (int d=0; d<4; d++) {
			int nx = cx + dx[d];
			int ny = cy + dy[d];

			if (nx<0||ny<0||nx>=5||ny>=5||visited[nx][ny]||!mark[nx][ny]) continue;
			visited[nx][ny] = true;
			q.push({nx, ny});
		}
	}

	return cnt;
}

bool check() {
	memset(visited, false, sizeof(visited));
	int sCnt = 0;
	bool checked = false;

	for (int i=0; i<5; i++) {
		for (int j=0; j<5; j++) {
			if (mark[i][j]) {
				if (!checked) {
					if (bfs(i, j) != 7) return false;
					checked = true;
				}
 				
				if (arr[i][j]) sCnt++;
			}
			
		}
	}
	return sCnt >= 4;
}

void bt(int idx, int cnt) {
	if (cnt == 7) {
		if (check()) ans++;
		return;
	}

	if (idx == 25) return;
	
	int x = idx/5;
	int y = idx%5;

	mark[x][y] = true;
	bt(idx+1, cnt+1);
	mark[x][y] = false;
	bt(idx+1, cnt);
}

int main() {
    ios::sync_with_stdio(false);
	cin.tie(0);

	char ch;
	for (int i=0; i<5; i++) {
		for (int j=0; j<5; j++) {
			cin >> ch;
			arr[i][j] = (ch =='S');
		}
	}

	bt(0, 0);

	cout<<ans;
    return 0;
}