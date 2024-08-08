#include <bits/stdc++.h>

#define PII pair<int,int>
#define PFF pair<float, float>

using namespace std;
typedef long long ll;

int arr[200001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, c, x, ans = 0;
    cin >> n >> c;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr, arr + n);
    int lo = 1, hi = arr[n - 1] - arr[0];

    while (lo <= hi) {
        int cnt = 1;
        int mid = (lo + hi) / 2;
        int pos = arr[0];

        for (int i = 1; i < n; i++) {
            if (arr[i] - pos >= mid) {
                cnt++;
                pos = arr[i];
            }
        }

        if (cnt >= c) {
            ans = max(ans, mid);
            lo = mid + 1;
        }
        else {
            hi = mid - 1;
        }
    }

    cout << ans;

    return 0;
}