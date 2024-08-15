#include <bits/stdc++.h>

#define PII pair<int,int>
#define PFF pair<float, float>

using namespace std;
typedef long long ll;

int n, m;
int arr[123457][3];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
    }

    ll lo = 1, hi = 1e12 * n, ans = 1e12 * n;

    while (lo <= hi) {
        ll mid = (lo + hi) / 2; //maxHealth
        ll curH = mid;
        ll atk = m;
        bool isWin = true;

        for (int i = 0; i < n; i++) {
            if (arr[i][0] == 1) {
                ll monAtk = arr[i][1];
                ll monH = arr[i][2];

                ll atkCnt = monH % atk ? monH / atk + 1: monH / atk;
                curH -= monAtk * (atkCnt - 1);

                if (curH <= 0) {
                    isWin = false;
                    break;
                }
            }

            else {
                atk += arr[i][1];
                curH = min(curH + arr[i][2], mid);
            }
        }

        if (isWin) {
            ans = min(ans, mid);
            hi = mid - 1;
        }
        else {
            lo = mid + 1;
        }

    }


    cout << ans;

    return 0;
}