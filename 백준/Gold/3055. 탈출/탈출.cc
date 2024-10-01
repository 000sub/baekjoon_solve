#include <iostream>
#include <vector>
#include <cstring>
#include <queue>

#define PII pair<int,int>
using namespace std;

constexpr int dx[] = {1,0,-1,0};
constexpr int dy[] = {0,1,0,-1};

int r,c,sx,sy;
char arr[51][51];
int Time[51][51];
bool visited[51][51];
vector<PII> waters;

struct QNode {
	int x;
	int y;
	int time;
};

void calcTime() {
	for (int i=0; i<r; i++) for (int j=0; j<c; j++) Time[i][j] = 1e9;
	queue<PII> q;
	for (PII& p : waters) {
		int wx = p.first;
		int wy = p.second;
		visited[wx][wy] = true;
		Time[wx][wy] = 0;
		q.push({wx, wy});
	}
	
	while (!q.empty()) {
		auto [x,y] = q.front();
		q.pop();

		for (int d=0; d<4; d++) {
			int nx = x + dx[d];
			int ny = y + dy[d];

			if (nx<0||ny<0||nx>=r||ny>=c||arr[nx][ny]!='.'||visited[nx][ny]||Time[nx][ny] < Time[x][y] + 1) continue;
			Time[nx][ny] = Time[x][y] + 1;
			visited[nx][ny] = true;
			q.push({nx,ny});
		}
	}
}

int main() {
    ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>r>>c;
	for (int i=0; i<r; i++) {
		for (int j=0; j<c; j++) {
			cin>>arr[i][j];
			if (arr[i][j]=='S') sx=i, sy=j;
			else if (arr[i][j]=='*') waters.push_back({i, j});
		}
	}

	calcTime();

	queue<QNode> q;
	memset(visited, false, sizeof(visited));
	visited[sx][sy] = true;
	q.push({sx, sy, 0});

	while (!q.empty()) {
		auto [x, y, curT] = q.front();
		q.pop();

		if (arr[x][y] == 'D') {
			cout<<curT;
			return 0;
		}

		for (int d=0;d<4;d++) {
			int nx = x + dx[d];
			int ny = y + dy[d];
			if (nx<0||ny<0||nx>=r||ny>=c||visited[nx][ny]||Time[nx][ny]<=curT+1||arr[nx][ny]=='X') continue;
			visited[nx][ny] = true;
			q.push({nx, ny, curT+1});
		}
	}
 
    cout << "KAKTUS";
    return 0;
}