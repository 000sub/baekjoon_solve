#include <bits/stdc++.h>
#include <unordered_set>
#define PII pair<int,int>
using namespace std;
typedef long long ll;

int T, N;
int dp[10001][4];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> T;

    for (int i = 1; i <= 3; i++) {
        for (int j = 1; j <= i; j++) {
            dp[i][j] = 1;
        }
    }

    for (int i = 4; i <= 10000; i++) {
        dp[i][1] = 1;
        dp[i][2] = dp[i - 2][1] + dp[i - 2][2];
        dp[i][3] = dp[i - 3][1] + dp[i - 3][2] + dp[i - 3][3];
    }

    while (T--) {
        cin >> N;
        cout << dp[N][1] + dp[N][2] + dp[N][3] << '\n';
    }

    return 0;
}