#include <bits/stdc++.h>

#define PII pair<int,int>
#define PFF pair<float, float>

using namespace std;
typedef long long ll;

int n, m;
int arr[100001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> arr[i];

    ll lo = 1, hi = 1e9, ans = 1e9;

    while (lo <= hi) {
        ll mid = (lo + hi) / 2;

        int cnt = 1;
        for (int i = 0, sum = 0; i < n; i++) {
            if (arr[i] > mid) {
                cnt = 1e9;
                break;
            }

            if (sum + arr[i] > mid) {
                cnt++;
                sum = arr[i];
            }
            else sum += arr[i];
        }

        if (cnt > m) {
            lo = mid + 1;
        }
        else {
            ans = min(ans, mid);
            hi = mid - 1;
        }
    }


    cout << ans;

    return 0;
}