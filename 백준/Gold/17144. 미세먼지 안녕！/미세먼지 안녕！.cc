#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int R,C,T;
int board[51][51], temp[51][51];
int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};
vector<int> fresher_rows;

void sparse() {
    memset(temp, 0, sizeof(temp));
    for (int i=0; i<R; i++) {
        for (int j=0; j<C; j++) {
            if (board[i][j] > 0) {
                int cnt = 0;
                for (int d=0; d<4; d++) {
                    int nx = i + dx[d];
                    int ny = j + dy[d];

                    if (nx<0||ny<0||nx>R-1||ny>C-1||board[nx][ny] == -1) continue;

                    cnt++;
                    temp[nx][ny] += board[i][j] / 5;
                }
                temp[i][j] -= (board[i][j]/5) * cnt;
            }
        }
    }

    for (int i=0; i<R; i++) {
        for (int j=0; j<C; j++) {
            board[i][j] += temp[i][j];
        }
    }
}

void fresh() {
    int first_pos = fresher_rows[0];
    int second_pos = fresher_rows[1];

    for (int i=first_pos-1; i>0; i--) {
        board[i][0] = board[i-1][0];
    }
    board[0][0] = 0;

    for (int i=0; i<C-1; i++) {
        board[0][i] = board[0][i+1];
    }
    board[0][C-1] = 0;

    for (int i=0; i<first_pos; i++) {
        board[i][C-1] = board[i+1][C-1];
    }
    board[first_pos][C-1] = 0;

    for (int i=C-1; i>1; i--) {
        board[first_pos][i] = board[first_pos][i-1];
    }
    board[first_pos][1] = 0;

    for (int i=second_pos+1; i<R-1; i++) {
        board[i][0] = board[i+1][0];
    }
    board[R-1][0] = 0;

    for (int i=0; i<C-1; i++) {
        board[R-1][i] = board[R-1][i+1];
    }
    board[R-1][C-1] = 0;

    for (int i=R-1; i>second_pos; i--) {
        board[i][C-1] = board[i-1][C-1];
    }
    board[second_pos][C-1] = 0;

    for (int i=C-1; i>1; i--) {
        board[second_pos][i] = board[second_pos][i-1];
    }
    board[second_pos][1] = 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>R>>C>>T;

    for (int i=0; i<R; i++) {
        for (int j=0; j<C; j++) {
            cin>>board[i][j];
            if (board[i][j] == -1) fresher_rows.push_back(i);
        }
    }

    while (T--) {
        sparse();
        fresh();
    }

    int ans = 0;
    for (int i=0; i<R; i++) {
        for (int j=0; j<C; j++) {
            if (board[i][j] > 0) ans += board[i][j];
        }
    }

    cout<<ans<<'\n';

    return 0;
}