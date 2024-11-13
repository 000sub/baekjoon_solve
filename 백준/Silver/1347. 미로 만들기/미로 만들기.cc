#include <bits/stdc++.h>
#include <unordered_set>
#define PII pair<int,int>
using namespace std;
typedef long long ll;

int N, dir = 1;
int minH = 50, maxH = 50, minW = 50, maxW = 50;
int curX = 50, curY = 50;
bool visited[101][101];
char ch;

int dx[] = { 0,1,0,-1 };
int dy[] = { 1,0,-1,0 };

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    visited[curX][curY] = true;

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> ch;
        if (ch == 'L') dir = (dir + 3) % 4;
        else if (ch == 'R') dir = (dir + 1) % 4;
        else {
            curX += dx[dir], curY += dy[dir];
            visited[curX][curY] = true;
            minH = min(curX, minH);
            maxH = max(curX, maxH);
            minW = min(curY, minW);
            maxW = max(curY, maxW);
        }
    }

    for (int i = minH; i <= maxH; i++) {
        for (int j = minW; j <= maxW; j++) {
            visited[i][j] ? cout << '.' : cout << '#';
        }
        cout << '\n';
    }


    return 0;
}