#include <bits/stdc++.h>

#define PII pair<int,int>
using namespace std;
typedef long long ll;

int N, T;
int K[101], S[101];
int dp[101][10001];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N >> T;

    for (int i = 0; i < N; i++) cin >> K[i] >> S[i];

    for (int i = 1; i <= N; i++) {
        int time = K[i-1];
        int score = S[i-1];

        for (int j = 0; j <= T; j++) {
            if (j >= time) dp[i][j] = max(dp[i - 1][j - time] + score, dp[i - 1][j]);
            else dp[i][j] = dp[i - 1][j];
        }
    }

    cout << dp[N][T];
    return 0;
}