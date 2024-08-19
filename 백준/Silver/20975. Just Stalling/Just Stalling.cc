#include <bits/stdc++.h>

#define PII pair<int,int>

typedef long long ll;
using namespace std;

int n;
int A[21], B[21];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    fill(B, B + 21, 2e9);

    cin >> n;
    for (int i = 0; i < n; i++) cin >> A[i];
    for (int i = 0; i < n; i++) cin >> B[i];

    sort(A, A + n, greater<>());
    sort(B, B + n);

    ll ans = 1;
    for (int i = 0; i < n; i++) {
        int cnt = B + n - lower_bound(B, B + n, A[i]);
        ans *= cnt - i;
    }

    cout << ans;

    return 0;
}