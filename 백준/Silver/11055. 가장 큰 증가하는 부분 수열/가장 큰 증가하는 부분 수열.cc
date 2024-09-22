#include <bits/stdc++.h>

#define PII pair<int,int>
#define PIII pair<int,PII>

using namespace std;
typedef long long ll;

int N;
int arr[1001], dp[1001];

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;

    for (int i = 0; i < N; i++) cin >> arr[i];
    dp[0] = arr[0];

    for (int i = 1; i < N; i++) {
        dp[i] = arr[i];
        for (int j = i; j >= 0; j--) {
            if (dp[i] < dp[j] + arr[i] && arr[i] > arr[j]) {
                dp[i] = dp[j] + arr[i];
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < N; i++) ans = max(ans, dp[i]);
    cout << ans;


    return 0;
}