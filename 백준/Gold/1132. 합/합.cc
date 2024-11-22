#include <bits/stdc++.h>
#include <unordered_set>
#define PII pair<int,int>
using namespace std;
typedef long long ll;

string s;
int N;
bool notZero[20];
pair<ll, int> val[20];
ll ans = 0;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> N;

    for (int i = 0; i < 20; i++) val[i].second = i;

    while (N--) {
        cin >> s;
        notZero[s[0] - 'A'] = true;
        for (int i = 0; i < s.size(); i++) {
            val[s[i] - 'A'].first += pow(10, s.size() - i - 1);
        }
    }

    sort(val, val + 20, greater<>());

    if (notZero[val[9].second]) {
        for (int i = 8; i >= 0; i--) {
            if (!notZero[val[i].second]) {
                swap(val[i], val[9]);
                break;
            }
        }
    }

    sort(val, val + 9, greater<>());
        
    for (int i = 0; i <= 9; i++) {
        ans += val[i].first * (9 - i);
    }

    cout << ans;
    return 0;
}