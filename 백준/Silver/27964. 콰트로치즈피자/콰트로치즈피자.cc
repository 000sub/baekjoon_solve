#include <bits/stdc++.h>
#include <unordered_set>
#define PII pair<int,int>
using namespace std;
typedef long long ll;

int N, cnt = 0;
string s;
unordered_set<string> used;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N;

    while (N--) {
        cin >> s;
        if (s.size() < 6) continue;

        if (s.substr(s.size() - 6) == "Cheese" && !used.count(s)) {
            used.insert(s);
            cnt++;
        }

    }

    cnt >= 4 ? cout << "yummy" : cout << "sad";
    return 0;
}