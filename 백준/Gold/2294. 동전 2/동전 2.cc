#include <bits/stdc++.h>

#define PII pair<int,int>
#define PFF pair<float, float>

using namespace std;
typedef long long ll;

int dp[10001];
int coins[101];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, k;
    cin >> n >> k;

    for (int i = 0; i < n; i++) cin >> coins[i];

    fill(dp, dp + k + 1, 1e9);

    dp[0] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = coins[i]; j <= k; j++) {
            dp[j] = min(dp[j], dp[j - coins[i]] + 1);
        }
    }

    dp[k] == 1e9 ? cout << -1 : cout << dp[k];

    return 0;
}