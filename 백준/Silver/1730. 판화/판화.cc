#include <bits/stdc++.h>

#define PII pair<int,int>
using namespace std;
typedef long long ll;

int N;
char arr[11][11];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) arr[i][j] = '.';
    string str;
    cin >> str;

    int x = 0, y = 0;
    for (char c : str) {
        switch (c) {
            case 'D':
                if (x >= N - 1) break;
                if (arr[x][y] != '+') arr[x][y] = arr[x][y] != '-' ? '|' : '+';
                x++;
                if (arr[x][y] != '+') arr[x][y] = arr[x][y] != '-' ? '|' : '+';
                break;
            case 'U':
                if (x <= 0) break;
                if (arr[x][y] != '+') arr[x][y] = arr[x][y] != '-' ? '|' : '+';
                x--;
                if (arr[x][y] != '+') arr[x][y] = arr[x][y] != '-' ? '|' : '+';
                break;
            case 'L':
                if (y <= 0) break;
                if (arr[x][y] != '+') arr[x][y] = arr[x][y] != '|' ? '-' : '+';
                y--;
                if (arr[x][y] != '+') arr[x][y] = arr[x][y] != '|' ? '-' : '+';
                break;
            case 'R':
                if (y >= N - 1) break;
                if (arr[x][y] != '+') arr[x][y] = arr[x][y] != '|' ? '-' : '+';
                y++;
                if (arr[x][y] != '+') arr[x][y] = arr[x][y] != '|' ? '-' : '+';
                break;
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << arr[i][j];
        }
        cout << '\n';
    }

    

    return 0;
}