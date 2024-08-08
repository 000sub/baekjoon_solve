#include <bits/stdc++.h>

#define PII pair<int,int>
#define PFF pair<float, float>

using namespace std;
typedef long long ll;
int arr[1001], dp[1001], minArr[1001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> arr[i];
    fill(minArr, minArr + 1001, 1e9);
    for (int i = 1; i <= n; i++) {

        int idx = lower_bound(minArr, minArr + i, arr[i]) - minArr;
        minArr[idx] = min(minArr[idx], arr[i]);
        dp[i] = idx + 1;
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) ans = max(ans, dp[i]);

    cout << ans;

    return 0;
}