#include <bits/stdc++.h>

#define PII pair<int,int>
#define PIII pair<int,PII>

using namespace std;
typedef long long ll;

int n, m;
bool arr[501][501], visited[501][501];
constexpr int dx[] = { 1,0,-1,0 };
constexpr int dy[] = { 0,1,0,-1 };

int bfs(int x, int y) {
    int cnt = 0;
    queue<PII> q;
    q.push({ x,y });
    visited[x][y] = true;
    while (!q.empty()) {
        auto [cx, cy] = q.front();
        q.pop();

        cnt++;

        for (int d = 0; d < 4; d++) {
            int nx = cx + dx[d];
            int ny = cy + dy[d];
            if (nx < 0 || ny < 0 || nx >= n || ny >= m || visited[nx][ny] || !arr[nx][ny]) continue;
            q.push({ nx, ny });
            visited[nx][ny] = true;
        }
    }

    return cnt;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) cin >> arr[i][j];

    int num = 0, maxW = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j] == 1 && !visited[i][j]) {
                num++;
                maxW = max(maxW, bfs(i, j));
            }
        }
    }

    cout << num << '\n' << maxW;
    return 0;
}