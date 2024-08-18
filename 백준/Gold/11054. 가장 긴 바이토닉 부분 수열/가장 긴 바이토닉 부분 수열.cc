#include <bits/stdc++.h>

#define PII pair<int,int>
#define PFF pair<float, float>

using namespace std;
typedef long long ll;

int n;
int arr[1001], dp[1001], dp2[1001], A[1001], B[1001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];
    fill(A, A + n, 1e9);
    fill(B, B + n, 1e9);

    for (int i = 0; i < n; i++) {
        int idx = lower_bound(A, A + i, arr[i]) - A;
        dp[i] = idx + 1;
        A[idx] = arr[i];

        idx = lower_bound(B, B + i, arr[n - 1 - i]) - B;
        dp2[n - 1 - i] = idx + 1;
        B[idx] = arr[n - 1 - i];
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans = max(ans, dp[i] + dp2[i] - 1);
    }

    cout << ans;
    
    return 0;
}