#include <bits/stdc++.h>

#define PII pair<int,int>
#define PIII pair<int,PII>

using namespace std;
typedef long long ll;

int T, n, sx, sy, ex, ey;
bool visited[301][301];
constexpr int dx[] = { 1,1,-1,-1,2,2,-2,-2 };
constexpr int dy[] = { 2,-2,2,-2,1,-1,1,-1};

typedef struct Node {
    int x;
    int y;
    int cnt;
} Node;

int bfs() {
    memset(visited, false, sizeof(visited));
    queue<Node> q;
    q.push({ sx,sy,0 });
    visited[sx][sy] = true;
    while (!q.empty()) {
        auto [x, y, cnt] = q.front();
        q.pop();

        if (x == ex && y == ey) return cnt;

        for (int d = 0; d < 8; d++) {
            int nx = x + dx[d];
            int ny = y + dy[d];
            if (nx < 0 || ny < 0 || nx >= n || ny >= n || visited[nx][ny]) continue;
            q.push({ nx, ny, cnt+1 });
            visited[nx][ny] = true;
        }
    }

    return 0;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> T;
    while (T--) {
        cin >> n >> sx >> sy >> ex >> ey;
        cout << bfs() << '\n';
    }
    return 0;
}