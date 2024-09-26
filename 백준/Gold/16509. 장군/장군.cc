#include <iostream>
#include <queue>
#define PII pair<int,int>
using namespace std;

PII d[][3] = {
	{{-1,0}, {-1,-1}, {-1,-1}},
	{{-1,0}, {-1,1}, {-1,1}},
	{{0,1},{-1,1},{-1,1}},
	{{0,1},{1,1},{1,1}},
	{{1,0},{1,-1},{1,-1}},
	{{1,0},{1,1},{1,1}},
	{{0,-1},{1,-1},{1,-1}},
	{{0,-1},{-1,-1},{-1,-1}}
};
bool visited[10][9];

struct Node {
	int x;
	int y;
	int cnt;
};

int r1, c1, r2, c2;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin>>r1>>c1>>r2>>c2;

	queue<Node> q;
	q.push({r1, c1, 0});
	visited[r1][c1] = true;
	while (!q.empty()){
		auto [x,y,cnt] = q.front();
		q.pop();

		if (x==r2 && y==c2) {
			cout << cnt;
			return 0;
		}

		for (int dir=0; dir<8; dir++) {
			int nx = x;
			int ny = y;
			bool canMove = true;
			for (int it=0; it<3; it++) {
				nx += d[dir][it].first;
				ny += d[dir][it].second;
				if (nx<0||ny<0||nx>9||ny>8||(it<2 && nx == r2 && ny == c2)) {
					canMove = false;
					break;
				}
			}
			if (canMove && !visited[nx][ny]) {
				q.push({nx, ny, cnt+1});
				visited[nx][ny] = true;
			}
		}
	}
	cout<<-1;

	return 0;
}