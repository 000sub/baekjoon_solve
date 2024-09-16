#include <iostream>
#include <algorithm>
#include <vector>

#define PII pair<int,int>
#define PIII pair<int,PII>

using namespace std;
typedef long long ll;

int r, c, n;
int arr[201][201];
int dx[] = {0,-1,0,1};
int dy[] = {1,0,-1,0};

void printMap() {
    for (int i=0; i<r; i++) {
        for (int j=0; j<c; j++) {
            if (arr[i][j] == -1) cout << '.';
            else cout << 'O';
        }
        cout<<'\n';
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> r >> c >> n;

    char ch;

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> ch;
            arr[i][j] = ch == '.' ?  -1 : 0;
        }
    }

    if (n==1) {
        printMap();
        return 0;
    }

    for (int k=2; k<=n; k++) {
        if (k%2 == 0) {
            for (int i=0;i<r;i++) {
                for (int j=0;j<c;j++) {
                    if (arr[i][j] == -1) {
                        arr[i][j] = k;
                    }
                }
            }
        }
        else {
            for (int i=0;i<r;i++) {
                for (int j=0;j<c;j++) {
                    if (arr[i][j] == k-3) {
                        arr[i][j] = -1;
                        for (int d=0; d<4; d++) {
                            int nx = i + dx[d];
                            int ny = j + dy[d];
                            if (nx<0||ny<0||nx>=r||ny>=c||arr[nx][ny]==k-3) continue;
                            arr[nx][ny] = -1;
                        }
                    }
                }
            }
        }
    }

    printMap();
    return 0;
}