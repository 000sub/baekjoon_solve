#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
#include <set>
#include <string>
#include <map>

#define PII pair<int,int>
using namespace std;

int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};
const int INF = 1e9;

int N, M, K;
int arr[21][21], dist[21][21];
bool visited[21][21];
int tx, ty;
PII src[401], tgt[401];
bool used[401];

struct QNode {
	int x;
	int y;
	int cnt;
};

void calcDist(int sx, int sy) {
	memset(visited, false, sizeof(visited));
	for (int i=0; i<N; i++) for (int j=0; j<N; j++) dist[i][j] = INF;
	dist[sx][sy] = 0;
	visited[sx][sy] = true;
	queue<QNode> q;
	q.push({sx, sy, 0});
	while (!q.empty()) {
		auto [x, y, cnt] = q.front();
		q.pop();

		for (int d=0; d<4; d++) {
			int nx = x + dx[d];
			int ny = y + dy[d];
			if (nx<0||ny<0||nx>=N||ny>=N||visited[nx][ny]||dist[nx][ny] < cnt+1||arr[nx][ny]==-1) continue;
			dist[nx][ny] = cnt+1;
			visited[nx][ny] = true;
			q.push({nx, ny, cnt+1});
		}
	}
}

int bfs(int sx, int sy, int ex, int ey) {
	memset(visited, false, sizeof(visited));
	visited[sx][sy] = true;
	queue<QNode> q;
	q.push({sx, sy, 0});
	while (!q.empty()) {
		auto [x, y, cnt] = q.front();
		q.pop();

		if (x == ex && y == ey) {
			return cnt;
		}

		for (int d=0; d<4; d++) {
			int nx = x + dx[d];
			int ny = y + dy[d];
			if (nx<0||ny<0||nx>=N||ny>=N||visited[nx][ny]||arr[nx][ny]==-1) continue;
			visited[nx][ny] = true;
			q.push({nx, ny, cnt+1});
		}
	}

	return INF;
}

int findNearest() {
	int minDist = INF;
	int minIdx = -1;

	calcDist(tx, ty);

	for (int i=0; i<M; i++) {
		if (!used[i]) {
			if (
				(dist[src[i].first][src[i].second] < minDist) ||
				(dist[src[i].first][src[i].second] == minDist && src[i].first < src[minIdx].first) ||
				(dist[src[i].first][src[i].second] == minDist && src[i].first == src[minIdx].first && src[i].second < src[minIdx].second)
			) {
				minDist = dist[src[i].first][src[i].second];
				minIdx = i;
			}
		}
	}

	if (minDist == INF) return -1;

	//연료 소모 계산
	K -= minDist;
	used[minIdx] = true;
	return minIdx;
}

bool isFinished() {
	for (int i=0; i<M; i++) {
		if (!used[i]) return false;
	}
	return true;
}

void input() {
	cin>>N>>M>>K;

	for (int i=0; i<N; i++) {
		for (int j=0; j<N; j++) {
			cin>>arr[i][j];
			if (arr[i][j] == 1) arr[i][j] = -1;
		}
	}
	cin>>tx>>ty;
	tx--; ty--;
	int x,y;
	for (int i=0; i<M; i++) {
		cin>>x>>y;
		src[i] = {x-1, y-1};
		cin>>x>>y;
		tgt[i] = {x-1, y-1};
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
    input();

	for (int i=0; i<M; i++) {
		int next = findNearest();
		if (K<0 || next == -1) break;
		tx = src[next].first;
		ty = src[next].second;
		int distToGoal = bfs(tx, ty, tgt[next].first, tgt[next].second);
		if (distToGoal == INF) {
			cout<<-1;
			return 0;
		};

		K -= distToGoal;
		if (K<0) {
			cout<<-1;
			return 0;
		}

		tx = tgt[next].first;
		ty = tgt[next].second;
		K += 2 * distToGoal; 
	}

	isFinished() ? cout<<K : cout<<-1;
    return 0;
}