#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
#define PII pair<int,int>

using namespace std;


vector<int> answers;
bool visited[1001][1001];
char board[1001][1001];
int M,N;
int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1,0,0};

void BFS(int x, int y) {
    queue<PII> q;
    q.push({x, y});
    visited[x][y] = true;

    while (!q.empty()) {
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();
        for (int d=0; d<4; d++) {
            int nx = cx + dx[d];
            int ny = cy + dy[d];

            if (nx<0||ny<0||nx>M-1||ny>N-1||board[nx][ny] == '1'||visited[nx][ny]) continue;

            q.push({nx, ny});
            visited[nx][ny] = true;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> M >> N;
    for (int i=0; i<M; i++) 
        for (int j=0; j<N; j++)
            cin>>board[i][j];

    for (int i=0; i<N; i++) {
        if (board[0][i]=='0') BFS(0, i);
    }

    for (int i=0; i<N; i++) {
        if (visited[M-1][i]) {
            cout<<"YES";
            return 0;
        }
    }
    cout<<"NO";

    return 0;
}