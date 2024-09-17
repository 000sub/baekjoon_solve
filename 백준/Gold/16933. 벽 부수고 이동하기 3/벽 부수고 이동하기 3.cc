#include <bits/stdc++.h>

#define PII pair<int,int>
#define PIII pair<int,PII>

using namespace std;
typedef long long ll;

int N, M, K;
int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };
int arr[1001][1001];
bool visited[1001][1001][11];

typedef struct Node {
    int x;
    int y;
    int mCnt;
    int bCnt;
    bool canBreak;
} Node;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M >> K;

    char ch;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> ch;
            arr[i][j] = ch == '0' ? 0 : 1;
        }
    }

    queue<Node> q;
    q.push({ 0,0,1,0,true });
    visited[0][0][0] = true;
    while (!q.empty()) {
        int x = q.front().x;
        int y = q.front().y;
        int mCnt = q.front().mCnt;
        int bCnt = q.front().bCnt;
        bool canBreak = q.front().canBreak;
        q.pop();

        if (x == N - 1 && y == M - 1) {
            cout << mCnt;
            return 0;
        }

        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d];
            int ny = y + dy[d];

            if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;

            if (arr[nx][ny] == 1 && bCnt < K && !visited[nx][ny][bCnt+1]) {
                if (canBreak) {
                    visited[nx][ny][bCnt + 1] = true;
                    q.push({ nx, ny, mCnt + 1, bCnt + 1, !canBreak });
                }
                else {
                    q.push({ x, y, mCnt + 1, bCnt, !canBreak });
                }
            }
            
            else if (!visited[nx][ny][bCnt] && arr[nx][ny] == 0) {
                visited[nx][ny][bCnt] = true;
                q.push({ nx, ny, mCnt + 1, bCnt, !canBreak });
            }
        }
    }
    cout << -1;
    return 0;
}