#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
#include <unordered_set>

#define PII pair<int,int>
#define PIII pair<int,PII>
#define PIIII pair<PII, PII>

using namespace std;
typedef long long ll;

int W, H, K;
int arr[201][201];
int visited[201][201][31];
int dx[] = {0,0,-1,1};
int dy[] = {1,-1,0,0};
int kdx[] = {-2,-2,-1,-1,1,1,2,2};
int kdy[] = {1,-1,2,-2,2,-2,1,-1};

int BFS() {
    queue<PIIII> q;
    q.push({{0,0}, {0,0}});
    visited[0][0][0] = true;

    while (!q.empty()) {
        int cnt = q.front().first.first;
        int jumped = q.front().first.second;
        int x = q.front().second.first;
        int y = q.front().second.second;
        q.pop();

        if (x==H-1 && y==W-1) {
            return cnt;
        }

        for (int d=0; d<4; d++) {
            int nx = x + dx[d];
            int ny = y + dy[d];
            if (nx<0||ny<0||nx>=H||ny>=W||arr[nx][ny]||visited[nx][ny][jumped]) continue;
            visited[nx][ny][jumped] = true;
            q.push({{cnt+1, jumped}, {nx, ny}});
        }

        if (jumped < K) {
            for (int d=0; d<8; d++) {
                int nx = x + kdx[d];
                int ny = y + kdy[d];

                if (nx<0||ny<0||nx>=H||ny>=W||arr[nx][ny]||visited[nx][ny][jumped+1]) continue;
                visited[nx][ny][jumped+1] = true;
                q.push({{cnt+1, jumped+1}, {nx,ny}});
            }
        }
    }

    return -1;
}

int main(void) {
	ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>K>>W>>H;

    for (int i=0; i<H; i++) for (int j=0; j<W; j++) cin>>arr[i][j];

    cout << BFS();
	return 0;
}