#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
#include <set>
#include <string>
#include <map>

#define PII pair<int,int>
using namespace std;
typedef long long ll;

int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};

char arr[1001][1001];
bool visited[11][1001][1001];
int N, M, K;

struct QNode {
	int x;
	int y;
	int dist;
	int cnt;
};

int bfs() {
	queue<QNode> q;
	q.push({0, 0, 0, 0});
	visited[0][0][0] = true;

	while (!q.empty()) {
		auto [x, y, dist, cnt] = q.front();
		q.pop();

		if (x == N-1 && y == M-1) return dist+1;

		for (int d=0; d<4; d++) {
			int nx = x + dx[d];
			int ny = y + dy[d];
			if (nx<0||ny<0||nx>=N||ny>=M||visited[cnt][nx][ny]) continue;
			if (arr[nx][ny] == '1' && cnt < K && !visited[cnt+1][nx][ny]) {
				visited[cnt+1][nx][ny] = true;
				q.push({nx, ny, dist+1, cnt+1});
			}
			else if (arr[nx][ny] == '0') {
				visited[cnt][nx][ny] = true;
				q.push({nx, ny, dist+1, cnt});
			}
		}
	}

	return -1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin>>N>>M>>K;
	
	for (int i=0; i<N; i++) for (int j=0; j<M; j++) cin>>arr[i][j];
	cout << bfs();
    
    return 0;
}