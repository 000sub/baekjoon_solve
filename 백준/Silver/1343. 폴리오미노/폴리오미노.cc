#include <bits/stdc++.h>
#include <unordered_set>
#define PII pair<int,int>
using namespace std;
typedef long long ll;

string s, ans = "";

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> s;

    for (int i = 0; i < s.size(); i++) {
        if (s.substr(i, 4) == "XXXX") {
            ans += "AAAA";
            i += 3;
        }
        else if (s.substr(i, 2) == "XX") {
            ans += "BB";
            i += 1;
        }
        else if (s[i] == '.') {
            ans += ".";
        }
        else {
            cout << -1;
            return 0;
        }
    }
    cout << ans;
    return 0;
}