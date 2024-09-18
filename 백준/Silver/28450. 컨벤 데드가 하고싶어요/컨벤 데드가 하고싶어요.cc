#include <bits/stdc++.h>

#define PII pair<int,int>
#define PIII pair<int,PII>

using namespace std;
typedef long long ll;

int N, M, H;
int arr[1001][1001];
ll dp[1001][1001];

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;
    for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) cin >> arr[i][j];
    cin >> H;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (i == 0 && j == 0) dp[i][j] = arr[i][j];
            else if (i == 0) dp[i][j] += dp[i][j-1] + arr[i][j];
            else if (j == 0) dp[i][j] += dp[i - 1][j] + arr[i][j];
            else dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + arr[i][j];
        }
    }

    if (dp[N - 1][M - 1] > H) {
        cout << "NO";
    }
    else {
        cout << "YES\n";
        cout << dp[N - 1][M - 1];
    }
    return 0;
}