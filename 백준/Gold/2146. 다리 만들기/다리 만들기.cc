#include <bits/stdc++.h>
#include <unordered_set>
#define PII pair<int,int>
using namespace std;
typedef long long ll;

int N, landIdx = 2, ans = 1e9;
int arr[101][101], mark[101][101];
bool visited[101][101], checked[10001];

int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };

struct QNode {
    int x;
    int y;
    int cnt;
};

void bfs(int sx, int sy) {
    queue<PII> q;
    q.push({ sx, sy });
    visited[sx][sy] = true;

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        mark[x][y] = landIdx;

        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d];
            int ny = y + dy[d];

            if (nx < 0 || ny < 0 || nx >= N || ny >= N || visited[nx][ny] || arr[nx][ny] == 0) continue;
            visited[nx][ny] = true;
            q.push({ nx, ny });
        }

    }
}

void calc(int k) {
    queue<QNode> q;
    memset(visited, false, sizeof(visited));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (mark[i][j] == k) visited[i][j] = true, q.push({ i, j, 0 });
        }
    }

    while (!q.empty()) {
        auto [x, y, cnt] = q.front();
        q.pop();

        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d];
            int ny = y + dy[d];

            if (nx < 0 || ny < 0 || nx >= N || ny >= N || visited[nx][ny] || mark[nx][ny] == k) continue;

            if (arr[nx][ny] != 0 && mark[nx][ny] != k) {
                ans = min(ans, cnt);
                return;
            }

            visited[nx][ny] = true;
            q.push({ nx, ny, cnt + 1 });
        }
    }
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) cin >> arr[i][j];

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (!visited[i][j] && arr[i][j] == 1) {
                bfs(i, j);
                landIdx++;
            }
        }
    }

    for (int i = 2; i < landIdx; i++) {
        calc(i);
    }

    cout << ans;
    return 0;
}