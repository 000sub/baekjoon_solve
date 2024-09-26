#include <bits/stdc++.h>

#define PII pair<int,int>
#define PIII pair<int,PII>
using namespace std;
typedef long long ll;
int N, M;
int ans = 0;
char arr[16][16];
bool visited[16][16];

struct Cross {
	int x;
	int y;
	int len;
};
vector<Cross> v;

int dx[] = { 0,1,0,-1 };
int dy[] = { 1,0,-1,0 };

int getWidth(int x) {
	return 1 + (x-1) * 4;
}

bool isOverlapped(Cross a, Cross b) {
	memset(visited, false, sizeof(visited));
	for (int i = -1 * a.len + 1; i <= a.len-1; i++) {
		visited[a.x][a.y + i] = true;
		visited[a.x + i][a.y] = true;
	}

	for (int i = -1 * b.len + 1; i <= b.len-1; i++) {
		if (visited[b.x][b.y + i] || visited[b.x + i][b.y])
			return false;
	}
	return true;
}

void simulate(Cross a, Cross b) {
	int aSize = a.len;
	int bSize = b.len;
	while (!isOverlapped({ a.x, a.y, aSize }, { b.x, b.y, bSize })) {
		if (aSize > bSize) aSize--;
		else bSize--;
	}

	ans = max(ans, getWidth(aSize) * getWidth(bSize));
}

void BFS(int x, int y) {
	int cnt = 1;
	while (true) {
		for (int d = 0; d < 4; d++) {
			int nx = x + dx[d] * cnt;
			int ny = y + dy[d] * cnt;
			if (nx < 0 || ny < 0 || nx >= N || ny >= M || arr[nx][ny] == '.') {
				v.push_back({ x, y, cnt });
				return;
			}
		}
		cnt++;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) cin >> arr[i][j];
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (arr[i][j] == '#') {
				BFS(i, j);
			}		
		}
	}

	for (int i = 0; i < v.size()-1; i++) {
		for (int j = i+1; j < v.size(); j++) {
			if (getWidth(v[i].len) * getWidth(v[j].len) > ans) {
				simulate(v[i], v[j]);
			}
		}
	}

	cout << ans;
	return 0;
}