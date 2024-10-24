#include <bits/stdc++.h>

#define PII pair<int,int>
using namespace std;
typedef long long ll;

int N;
string str;
vector<string> v;
set<char> ans;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> str;
        v.push_back(str);
    }

    for (char c = 'A'; c <= 'Z'; c++) {
        int cnt = 0;

        for (int i = 0; i < N; i++) {
            if (v[i][0] == c) cnt++;
        }

        if (cnt == 0) continue;

        for (int i = 0; i < N; i++) {
            if (cnt == 1 && v[i][0] == c) continue;
            ans.insert(max(c, v[i][1]));
        }
    }
    cout << ans.size() << '\n';
    for (auto& c : ans) cout << c << " ";
    return 0;
}