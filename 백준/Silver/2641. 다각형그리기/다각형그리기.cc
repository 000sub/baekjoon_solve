#include <bits/stdc++.h>
#include <unordered_set>
#define PII pair<int,int>
using namespace std;
typedef long long ll;

int N, M, ansCnt = 0;
string pat = "", revPat = "";
set<string> validPatterns;

vector<string> ans;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> N;

    for (int i = 0, temp; i < N; i++) {
        cin >> temp;
        pat += temp + '0';
        revPat += (temp % 2) ? (4 - temp) + '0' : (6 - temp) + '0';
    }

    reverse(revPat.begin(), revPat.end());
    pat += pat; revPat += revPat;

    for (int i = 0; i < N; i++) {
        validPatterns.insert(pat.substr(i, N));
        validPatterns.insert(revPat.substr(i, N));
    }

    cin >> M;
    for (int i = 0; i < M; i++) {
        string s = "";
        for (int j = 0, temp; j < N; j++) {
            cin >> temp;
            s += temp + '0';
        }
        if (validPatterns.count(s)) {
            ansCnt++;
            ans.push_back(s);
        }
    }

    cout << ansCnt << '\n';
    for (auto str : ans) {
        for (char c : str) {
            cout << c << " ";
        }
        cout << '\n';
    }
    return 0;
}