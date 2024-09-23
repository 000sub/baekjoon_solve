#include <bits/stdc++.h>

#define PII pair<int,int>
#define PIII pair<int,PII>

using namespace std;
typedef long long ll;

int N,L,R,X,ans=0;
int arr[15];

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> L >> R >> X;
    for (int i = 0; i < N; i++) cin >> arr[i];

    for (int i = 3; i < (1 << N); i++) {
        int cnt = 0, sum = 0, lo = 2e9, hi = 0;
        for (int j = 0; j < N; j++) {
            if (i & (1 << j)) {
                cnt++;
                sum += arr[j];
                lo = min(lo, arr[j]);
                hi = max(hi, arr[j]);
            }
        }
        if (cnt >= 2 && sum >= L && sum <= R && hi - lo >= X) ans++;
    }
    cout << ans;

    return 0;
}