#include <bits/stdc++.h>

#define PII pair<int,int>
using namespace std;
typedef long long ll;

int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };

int N, M;
int arr[1001][1001], cntNum[1001][1001];
bool visited[1001][1001];
int cnt[1000001];
int cnt_idx = 1;

int bfs(int sx, int sy) {
    queue<PII> q;
    int res = 0;
    q.push({ sx, sy });
    visited[sx][sy] = true;

    while (!q.empty()) {
        auto [x, y] = q.front();
        
        res++;
        cntNum[x][y] = cnt_idx;
        q.pop();

        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d];
            int ny = y + dy[d];
            if (nx < 0 || ny < 0 || nx >= N || ny >= M || visited[nx][ny] || arr[nx][ny] == 0) continue;
            visited[nx][ny] = true;
            q.push({ nx,ny });
        }
    }
    
    return res;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N >> M;
    for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) cin >> arr[i][j];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (!visited[i][j] && arr[i][j] == 1) {
                cnt[cnt_idx++] = bfs(i, j);
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (arr[i][j] == 0) {
                set<int> ids;
                int sum = 0;
                for (int d = 0; d < 4; d++) {
                    int nx = i + dx[d];
                    int ny = j + dy[d];
                    if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
                    if (cntNum[nx][ny] > 0 && !ids.count(cntNum[nx][ny])) {
                        sum += cnt[cntNum[nx][ny]];
                        ids.insert(cntNum[nx][ny]);
                    }
                }
                ans = max(ans, sum);
            }
        }
    }

    cout << ans + 1;

    return 0;
}