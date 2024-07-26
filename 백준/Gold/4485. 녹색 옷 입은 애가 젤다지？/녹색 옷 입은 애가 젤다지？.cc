#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define PII pair<int,int>

using namespace std;
typedef long long ll;
int n, cnt = 0;
int board[126][126];
int dist[126][126];
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };
int ans;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	while (cin >> n) {
		if (n == 0) return 0;

		cnt++;
		ans = 1e9;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> board[i][j];
				dist[i][j] = 1e9;
			}
		}

		priority_queue < pair<int, PII>, vector<pair<int, PII>>, greater<pair<int, PII>>> pq;

		pq.push(make_pair(board[0][0], PII(0,0)));

		while (!pq.empty()) {
			int cost = pq.top().first;
			int x = pq.top().second.first;
			int y = pq.top().second.second;
			pq.pop();

			if (dist[x][y] < cost) continue;

			dist[x][y] = cost;

			if (x == n - 1 && y == n - 1) {
				ans = min(ans, cost);
				continue;
			}

			for (int d = 0; d < 4; d++) {
				int nx = x + dx[d];
				int ny = y + dy[d];

				if (nx < 0 || ny < 0 || nx > n - 1 || ny > n - 1) continue;

				int newDist = cost + board[nx][ny];
				if (dist[nx][ny] > newDist) {
					dist[nx][ny] = newDist;
					pq.push(make_pair(newDist, PII(nx, ny)));
				}
			}

		}

		cout << "Problem " << cnt << ": " << ans << '\n';
	}
	return 0;
}