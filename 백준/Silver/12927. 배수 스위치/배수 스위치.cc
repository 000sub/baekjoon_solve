#include <bits/stdc++.h>
#include <unordered_set>
#define PII pair<int,int>
using namespace std;
typedef long long ll;

bool used[1001];
int ans = 0;
string s;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> s;
    while (1) {
        bool finished = true;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 'Y') {
                if (used[i]) {
                    cout << -1;
                    return 0;
                }
                for (int j = i; j < s.size(); j += i+1) {
                    s[j] = (s[j] == 'Y') ? 'N' : 'Y';
                }

                ans++;
                finished = false;
                break;
            }
        }

        if (finished) {
            cout << ans;
            break;
        }
    }
    return 0;
}