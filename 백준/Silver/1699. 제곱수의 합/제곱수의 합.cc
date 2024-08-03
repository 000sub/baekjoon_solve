#include <bits/stdc++.h>

#define PII pair<int,int>
#define PFF pair<float, float>

using namespace std;
typedef long long ll;

int dp[100001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) dp[i] = i;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j * j <= i; j++) {
            dp[i] = min(dp[i], dp[i - j * j] + 1);
        }
    }
    cout << dp[n];


    return 0;
}