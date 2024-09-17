#include <bits/stdc++.h>

#define PII pair<int,int>
#define PIII pair<int,PII>

using namespace std;
typedef long long ll;

int r, s;
char arr[3001][3001];
int A[3001], B[3001]; //유성, 땅

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    memset(A, -1, sizeof(A));

    cin >> r >> s;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < s; j++) {
            cin >> arr[i][j];

            if (arr[i][j] == 'X') {
                A[j] = i;
            }
            else if (arr[i][j] == '#') {
                if (B[j] == 0) B[j] = i;
            }
        }
    }

    int gap = 1e9;
    for (int i = 0; i < s; i++) if(A[i]!=-1) gap = min(gap, B[i] - A[i]);

    for (int i = r - 1; i >= 0; i--) {
        for (int j = 0; j < s; j++) {
            if (arr[i][j] == 'X') {
                arr[i][j] = '.';
                arr[i + gap - 1][j] = 'X';
            }
        }
    }

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < s; j++) {
            cout << arr[i][j];
        }
        cout << '\n';
    }

    return 0;
}