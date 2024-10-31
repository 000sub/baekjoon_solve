#include <bits/stdc++.h>
#include <unordered_set>
#define PII pair<int,int>
using namespace std;
typedef long long ll;

map<string, int> m = {
    {"a",1},{"b",2},{"k",3},{"d",4},{"e",5},{"g",6},{"h",7},
    {"i",8},{"l",9},{"m",10},{"n",11},{"ng",12},{"o",13},
    {"p",14},{"r",15},{"s",16},{"t",17},{"u",18},{"w",19},{"y",20} 
};

int N;
string s;
vector<vector<string>> words;
vector<string> tmp;


bool cmp(vector<string>& a, vector<string>& b) {
    int len = min(a.size(), b.size());
    for (int i = 0; i < len; i++) {
        if (m[a[i]] != m[b[i]]) return m[a[i]] < m[b[i]];
    }

    return a.size() < b.size();
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N;

    while (N--) {
        cin >> s;
        for (int i = 0; i < s.size(); i++) {
            if (i < s.size() - 1 && s[i] == 'n' && s[i + 1] == 'g') {
                tmp.push_back("ng");
                i++;
            }
            else {
                tmp.push_back(string(1, s[i]));
            }
        }
        words.push_back(tmp);
        tmp.clear();
    }

    sort(words.begin(), words.end(), cmp);
    for (auto& v : words) {
        string ans = "";
        for (string k : v) ans += k;
        cout << ans << '\n';
    }
    return 0;
}