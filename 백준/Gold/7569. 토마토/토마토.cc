#include <bits/stdc++.h>

#define PII pair<int,int>
#define PIII pair<int,PII>

using namespace std;
typedef long long ll;

int N, M, H, maxTime = 0;
int arr[101][101][101];
bool visited[101][101][101];
int dx[] = { 0,0,1,-1,0,0 };
int dy[] = { 1,-1,0,0,0,0 };
int dz[] = { 0,0,0,0,1,-1 };
queue<pair<PII, PII>> q; //time, z, x, y

bool isFinished() {
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < M; k++) {
                if (arr[i][j][k] == 0) return false;
            }
        }
    }
    return true;
}

void BFS() {
    while (!q.empty()) {
        int time = q.front().first.first;
        int z = q.front().first.second;
        int x = q.front().second.first;
        int y = q.front().second.second;
        q.pop();

        maxTime = max(maxTime, time);

        for (int d = 0; d < 6; d++) {
            int nz = z + dz[d];
            int nx = x + dx[d];
            int ny = y + dy[d];

            if (nx < 0 || ny < 0 || nz < 0 || nx >= N || ny >= M || nz >= H || arr[nz][nx][ny] == -1 || visited[nz][nx][ny]) continue;
            q.push({ { time + 1, nz }, { nx,ny } });
            arr[nz][nx][ny] = time + 1;
            visited[nz][nx][ny] = true;
        }
    }
    

}
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> M >> N >> H;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < M; k++) {
                cin >> arr[i][j][k];
                if (arr[i][j][k] == 1) {
                    q.push({ {0 ,i}, {j, k} });
                    visited[i][j][k] = true;
                }
            }
        }
    }

    BFS();
    isFinished() ? cout << maxTime : cout<<-1;
    return 0;
}