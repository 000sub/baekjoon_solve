#include <bits/stdc++.h>

#define PII pair<int,int>
#define PIII pair<int,PII>

using namespace std;
typedef long long ll;

typedef struct Item {
    int x, y, dir;
} Item;

int N, K;
int dx[] = { 0,0,0,-1,1 };
int dy[] = { 0,1,-1,0,0 };
Item items[11];
deque<int> board[13][13];
int boardColor[13][13];

void moveToRed(int idx) {
    int sx = items[idx].x;
    int sy = items[idx].y;
    int nx = sx + dx[items[idx].dir];
    int ny = sy + dy[items[idx].dir];

    queue<int> q;

    while (board[sx][sy].front() != idx) {
        items[board[sx][sy].front()].x = nx;
        items[board[sx][sy].front()].y = ny;
        q.push(board[sx][sy].front());
        board[sx][sy].pop_front();
    }
    items[board[sx][sy].front()].x = nx;
    items[board[sx][sy].front()].y = ny;
    q.push(board[sx][sy].front());
    board[sx][sy].pop_front();

    while (!q.empty()) {
        board[nx][ny].push_front(q.front());
        q.pop();
    }
}

void moveToWhite(int idx) {
    int sx = items[idx].x;
    int sy = items[idx].y;
    int nx = sx + dx[items[idx].dir];
    int ny = sy + dy[items[idx].dir];

    stack<int> st;

    while (board[sx][sy].front() != idx) {
        items[board[sx][sy].front()].x = nx;
        items[board[sx][sy].front()].y = ny;
        st.push(board[sx][sy].front());
        board[sx][sy].pop_front();
    }
    items[board[sx][sy].front()].x = nx;
    items[board[sx][sy].front()].y = ny;
    st.push(board[sx][sy].front());
    board[sx][sy].pop_front();

    while (!st.empty()) {
        board[nx][ny].push_front(st.top());
        st.pop();
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> boardColor[i][j];
        }
    }

    for (int i = 1; i <= K; i++) {
        cin >> items[i].x >> items[i].y >> items[i].dir;
        board[--items[i].x][--items[i].y].push_back(i);
    }

    for (int t = 1; t <= 1000; t++) {
        for (int i = 1; i <= K; i++) {
            int nx = items[i].x + dx[items[i].dir];
            int ny = items[i].y + dy[items[i].dir];

            if (nx < 0 || ny < 0 || nx > N - 1 || ny > N - 1 || boardColor[nx][ny] == 2) {
                if (items[i].dir == 1 || items[i].dir == 3) items[i].dir++;
                else items[i].dir--;

                nx = items[i].x + dx[items[i].dir];
                ny = items[i].y + dy[items[i].dir];

                if (nx < 0 || ny < 0 || nx > N - 1 || ny > N - 1 || boardColor[nx][ny] == 2) continue;
                else if (boardColor[nx][ny] == 1) moveToRed(i);
                else moveToWhite(i);
            }

            else if (boardColor[nx][ny] == 1) moveToRed(i);
            else moveToWhite(i);
        
            if (board[nx][ny].size() >= 4) {
                cout << t;
                return 0;
            }
        }
    }

    cout << -1;
    return 0;
}