#include <bits/stdc++.h>

#define PII pair<int,int>
#define PFF pair<float, float>

using namespace std;
typedef long long ll;
const int mod = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    string s;
    
    cin >> n;

    for (int tc=1; tc<=n; tc++) {
        cin >> s;
        ll cnt = 0;

        if (s.size() == 1) {
            cout << "Case #" << tc << ": " << 1 << '\n';
            continue;
        }

        for (int i = 0; i < s.size(); i++) {
            if (i == 0) {
                if (s[i] == s[i + 1]) {
                    cnt = 1;
                }
                else {
                    cnt = 2;
                }
                continue;
            }

            if (i == s.size() - 1) {
                if (s[i-1] != s[i]) {
                    cnt *= 2;
                    cnt %= mod;
                }
                continue;
            }

            int temp = 0;
            if (s[i] != s[i - 1]) temp++;
            if (s[i] != s[i + 1]) temp++;
            if (s[i - 1] != s[i + 1]) temp++;

            if (temp > 1) {
                cnt *= temp;
                cnt %= mod;
            }
            
        }
        cout << "Case #" << tc << ": " << cnt << '\n';
    }


    return 0;
}