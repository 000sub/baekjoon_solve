#include <bits/stdc++.h>

#define PII pair<int,int>
using namespace std;
typedef long long ll;

constexpr int dx[] = { 1,0,-1,0,0,0 };
constexpr int dy[] = { 0,1,0,-1,0,0 };
constexpr int dz[] = { 0,0,0,0,1,-1 };

int L, R, C;
int sx, sy, sz, ex, ey, ez;
char arr[31][31][31];
bool visited[31][31][31];

struct QNode {
	int x;
	int y;
	int z;
	int cnt;
};
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	while (cin >> L >> R >> C) {
		if (L == 0 && R == 0 && C == 0) break;
		
		for (int i = 0; i < L; i++) {
			for (int j = 0; j < R; j++) {
				for (int k = 0; k < C; k++) {
					cin >> arr[i][j][k];
					if (arr[i][j][k] == 'S') sz = i, sx = j, sy = k;
					else if (arr[i][j][k] == 'E') ez = i, ex = j, ey = k;
				}
			}
		}

		bool escaped = false;
		queue<QNode> q;
		memset(visited, false, sizeof(visited));
		q.push({ sx, sy, sz, 0 });
		visited[sz][sx][sy] = true;
		while (!q.empty()) {
			auto [x, y, z, cnt] = q.front();
			q.pop();

			if (x == ex && y == ey && z == ez) {
				cout << "Escaped in " << cnt << " minute(s).\n";
				escaped = true;
				break;
			}

			for (int d = 0; d < 6; d++) {
				int nx = x + dx[d];
				int ny = y + dy[d];
				int nz = z + dz[d];

				if (nx < 0 || ny < 0 || nz < 0 || nx >= R || ny >= C || nz >= L || visited[nz][nx][ny] || arr[nz][nx][ny] == '#') continue;
				visited[nz][nx][ny] = true;
				q.push({ nx, ny, nz, cnt + 1 });
			}
		}
		if (!escaped) cout << "Trapped!\n";
	}

	return 0;
}