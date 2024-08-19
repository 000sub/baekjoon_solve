#include <bits/stdc++.h>

#define PII pair<int,int>

using namespace std;

typedef struct Route {
	int dist;
	int from;
	int to;
} Route;

const int INF = 1e9;

int N, M, ans = 0;
int arr[101][101];
vector<PII> lands[6];
int lands_idx = 0;
bool visited[101][101];
int dist[6][6];
int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };
vector<Route> v;
int parent[6]; 

int Find(int x) {
	if (parent[x] == x) return x;
	return parent[x] = Find(parent[x]);
}

void Union(int x, int y) {
	x = Find(x);
	y = Find(y);

	if (x == y) return;

	if (parent[x] > parent[y]) parent[x] = y;
	else parent[y] = parent[x];
}

bool cmp(Route& a, Route& b) {
	return a.dist < b.dist;
}

void searchLand() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (arr[i][j] == 1 && !visited[i][j]) {

				queue<PII> q;
				q.push({ i, j });
				visited[i][j] = true;

				while (!q.empty()) {
					int cx = q.front().first;
					int cy = q.front().second;
					q.pop();

					lands[lands_idx].push_back({ cx, cy });

					for (int d = 0; d < 4; d++) {
						int nx = cx + dx[d];
						int ny = cy + dy[d];

						if (nx<0 || ny<0 || nx>N - 1 || ny>M - 1 || visited[nx][ny] || arr[nx][ny] == 0) continue;

						visited[nx][ny] = true;
						q.push({ nx, ny });
					}
				}

				lands_idx++;
			}
		}
	}
}

void findRoute() {
	for (int i = 0; i < lands_idx; i++) {
		fill(dist[i], dist[i] + lands_idx, INF);
	}

	for (int i = 0; i < lands_idx - 1; i++) {
		for (int j = i + 1; j < lands_idx; j++) {
			for (PII p1 : lands[i]) {
				for (PII p2 : lands[j]) {
					int val = 1;
					bool isValid = true;
					if (p1.first == p2.first) {
						val = abs(p1.second - p2.second) - 1;

						int start = p1.second > p2.second ? p2.second + 1 : p1.second + 1;
						int end = p1.second > p2.second ? p1.second : p2.second;

						for (int k = start; k < end; k++) {
							if (arr[p1.first][k] != 0) {
								isValid = false;
								break;
							}
						}
					}
					else if (p1.second == p2.second) {
						val = abs(p1.first - p2.first) - 1;

						int start = p1.first > p2.first ? p2.first + 1 : p1.first + 1;
						int end = p1.first > p2.first ? p1.first : p2.first;

						for (int k = start; k < end; k++) {
							if (arr[k][p1.second] != 0) {
								isValid = false;
								break;
							}
						}
					}
					
					if (val == 1 || !isValid) continue;
					dist[i][j] = min(dist[i][j], val);
				}
			}
		}
	}

	for (int i = 0; i < lands_idx; i++) {
		for (int j = i + 1; j < lands_idx; j++) {
			if (dist[i][j] != INF)
				v.push_back({ dist[i][j], i, j });
		}
	}
}

bool isAllConnected() {
	for (int i = 0; i < lands_idx; i++) {
		if (Find(parent[i]) != 0) return false;
	}
	return true;
}

void kruskal() {
	for (int i = 0; i < lands_idx; i++) parent[i] = i;
	sort(v.begin(), v.end(), cmp);

	int vIdx = 0;
	int vSize = v.size();
	while (!isAllConnected()) {
		if (vIdx == vSize) break;

		Route r = v[vIdx++];
		if (Find(parent[r.from]) == Find(parent[r.to])) continue;
		Union(r.from, r.to);
		ans += r.dist;
	}
}

int main(void) {
	ios::sync_with_stdio(false);

	cin >> N >> M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> arr[i][j];

	searchLand();
	findRoute();
	kruskal();
	isAllConnected() ? cout << ans : cout << -1;
	
	return 0;
}