#include <bits/stdc++.h>

#define PII pair<int,int>
#define PFF pair<float, float>

using namespace std;
typedef long long ll;

int n, k, ans = 1e9;
ll d;
int rules[10001][3];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> k >> d;
    for (int i = 0; i < k; i++) {
        cin >> rules[i][0] >> rules[i][1] >> rules[i][2];
    }

    int lo = 1, hi = n;

    while (lo <= hi) {
        int mid = (lo + hi) / 2;

        ll cnt = 0;
        for (int i = 0; i < k; i++) {
            int start = rules[i][0];
            int end = rules[i][1];
            int gap = rules[i][2];

            end = min(end, mid);
            if (start <= end) cnt += (end - start) / gap + 1;
        }

        if (cnt < d) {
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