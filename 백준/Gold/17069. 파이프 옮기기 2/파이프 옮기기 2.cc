#include <bits/stdc++.h>

#define PII pair<int,int>
#define PIII pair<int,PII>

using namespace std;
typedef long long ll;

int N;
ll dp[33][33][3];
int arr[33][33];

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) cin >> arr[i][j];
    dp[0][1][0] = 1;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (arr[i][j]) continue;
            if (i == 0 && j < 2) continue;
            if (j > 0) dp[i][j][0] += dp[i][j - 1][0] + dp[i][j-1][1];
            if (i > 0 && j > 0 && !arr[i - 1][j] && !arr[i][j - 1]) dp[i][j][1] += dp[i - 1][j - 1][0] + dp[i - 1][j - 1][1] + dp[i - 1][j - 1][2];
            if (i > 0) dp[i][j][2] += dp[i - 1][j][1] + dp[i - 1][j][2];
        }
    }

    cout << dp[N - 1][N - 1][0] + dp[N - 1][N - 1][1] + dp[N - 1][N - 1][2];

    return 0;
}