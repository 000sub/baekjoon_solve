#include <bits/stdc++.h>

#define PII pair<int,int>
#define PFF pair<float, float>

using namespace std;
typedef long long ll;

int board[21][21];
int n, m, x, y, k;
int dx[] = {0,0,0,-1,1};
int dy[] = {0,1,-1,0,0};
int dice[6] = { 0, };
int temp[6];

void copyDice() {
    for (int i = 0; i < 6; i++) dice[i] = temp[i];
}

void moveUp() {
    temp[0] = dice[2];
    temp[1] = dice[1];
    temp[2] = dice[5];
    temp[3] = dice[3];
    temp[4] = dice[0];
    temp[5] = dice[4];
    copyDice();
}

void moveDown() {
    temp[0] = dice[4];
    temp[1] = dice[1];
    temp[2] = dice[0];
    temp[3] = dice[3];
    temp[4] = dice[5];
    temp[5] = dice[2];
    copyDice();
}

void moveLeft() {
    temp[0] = dice[3];
    temp[1] = dice[0];
    temp[2] = dice[2];
    temp[3] = dice[5];
    temp[4] = dice[4];
    temp[5] = dice[1];
    copyDice();
}

void moveRight() {
    temp[0] = dice[1];
    temp[1] = dice[5];
    temp[2] = dice[2];
    temp[3] = dice[0];
    temp[4] = dice[4];
    temp[5] = dice[3];
    copyDice();
 }

void move(int op) {
    switch (op) {
    case 1:
        moveRight();
        break;
    case 2:
        moveLeft();
        break;
    case 3:
        moveUp();
        break;
    case 4:
        moveDown();
        break;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    
    cin >> n >> m >> x >> y >> k;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }


    int op;

    for (int i = 0; i < k; i++) {
        cin >> op;
        int nx = x + dx[op];
        int ny = y + dy[op];
        if (nx<0 || ny<0 || nx>n - 1 || ny>m - 1) continue;

        move(op);

        if (board[nx][ny] == 0) {
            board[nx][ny] = dice[5];
        }
        else {
            dice[5] = board[nx][ny];
            board[nx][ny] = 0;
        }

        x = nx;
        y = ny;
        cout << dice[0] << '\n';
    }



    return 0;
}