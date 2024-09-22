#include <bits/stdc++.h>

#define PII pair<int,int>
#define PIII pair<int,PII>

using namespace std;
typedef long long ll;

bool visited[21][21][1<<10];
char arr[21][21];
constexpr int dx[] = {1,0,-1,0};
constexpr int dy[] = {0,1,0,-1};
int w, h, sx, sy;
vector<PII> v;
struct Node {
    int x;
    int y;
    int state;
    int moveCnt;
};


int bfs() {
    queue<Node> q;
    q.push({ sx,sy,0,0 });
    visited[sx][sy][0] = true;
    while (!q.empty()) {
        auto [x, y, state, moveCnt] = q.front();
        q.pop();

        if (state == (1 << v.size()) - 1) {
            return moveCnt;
        }

        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d];
            int ny = y + dy[d];

            if (nx < 0 || ny < 0 || nx >= h || ny >= w || arr[nx][ny] == 'x' || visited[nx][ny][state]) continue;

            if (arr[nx][ny] == '*') {
                int idx = 0;
                for (int i = 0; i < v.size(); i++) {
                    if (v[i].first == nx && v[i].second == ny) {
                        idx = i;
                        break;
                    }
                }
                q.push({ nx, ny, state | (1 << idx), moveCnt + 1 });
                visited[nx][ny][state | (1 << idx)] = true;
            }
            else {
                q.push({ nx, ny, state, moveCnt + 1 });
                visited[nx][ny][state] = true;
            }

        }
    }

    return -1;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    while (cin >> w >> h) {
        if (w == 0 && h == 0) break;

        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                cin >> arr[i][j];
                if (arr[i][j] == 'o') sx = i, sy = j;
                else if (arr[i][j] == '*') v.push_back({ i, j });
            }
        }

        cout << bfs() << '\n';

        memset(visited, false, sizeof(visited));
        v.clear();
    }

    return 0;
}