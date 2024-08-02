#include <bits/stdc++.h>

#define PII pair<int,int>
#define PIII pair<int,PII>
#define PFF pair<float, float>

using namespace std;
typedef long long ll;

int arr[5][5];
int r, c;
bool visited[5][5];
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			cin >> arr[i][j];
	
	cin >> r >> c;

	queue<PIII> q;
	q.push(make_pair(0, PII(r,c)));
	visited[r][c] = true;

	while (!q.empty()) {
		int cost = q.front().first;
		int x = q.front().second.first;
		int y = q.front().second.second;
		q.pop();

		if (arr[x][y] == 1) {
			cout << cost;
			return 0;
		}

		for (int d = 0; d < 4; d++) {
			int nx = x + dx[d];
			int ny = y + dy[d];

			if (nx < 0 || ny < 0 || nx>4 || ny>4 || visited[nx][ny] || arr[nx][ny] == -1) continue;

			visited[nx][ny] = true;
			q.push(make_pair(cost + 1, PII(nx, ny)));
		}
	}

	cout << -1;
	return 0;
}