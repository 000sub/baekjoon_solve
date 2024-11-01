#include <bits/stdc++.h>
#include <unordered_set>
#define PII pair<int,int>
using namespace std;
typedef long long ll;

string s, ans = "";
vector<int> idxs;

void check() {
    string a = s.substr(0, idxs[0]);
    string b = s.substr(idxs[0], idxs[1] - idxs[0]);
    string c = s.substr(idxs[1]);

    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    reverse(c.begin(), c.end());

    string tmp = "";
    tmp += a;
    tmp += b;
    tmp += c;

    if (ans == "") ans = tmp;
    else {
        ans = ans < tmp ? ans : tmp;
    }
}

void bt(int idx, int cnt) {
    if (cnt == 2) {
        check();
        return;
    }

    for (int i = idx + 1; i < s.size(); i++) {
        idxs.push_back(i);
        bt(i, cnt + 1);
        idxs.pop_back();
    }
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> s;

    bt(0, 0);
    cout << ans;
    return 0;
}