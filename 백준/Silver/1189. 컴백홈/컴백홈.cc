#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

typedef struct Node {
	int x;
	int y;
	int cnt;
	int visited;
} Node;

int R, C, K;
bool isWall[6][6];
int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin>>R>>C>>K;

	char ch;

	for (int i=0; i<R; i++) {
		for (int j=0; j<C; j++) {
			cin>>ch;
			if (ch=='T') isWall[i][j] = true;
		}
	}

	queue<Node> q;
	int ans = 0;
	q.push({R-1, 0, 1, 1<<((R-1) * C)});
	while (!q.empty()) {
		auto [x, y, cnt, visited] = q.front();
		q.pop();

		if (x==0 && y==C-1) {
			if (cnt == K) ans++;
			continue;
		}

		for (int d=0; d<4; d++) {
			int nx = x + dx[d];
			int ny = y + dy[d];

			if (nx<0||ny<0||nx>=R||ny>=C||isWall[nx][ny]) continue;
			if (visited & (1<<(nx*C+ny))) continue;

			q.push({nx,ny,cnt+1, visited | (1<<(nx*C+ny))});
		}
	}
	cout<<ans;
	return 0;
}