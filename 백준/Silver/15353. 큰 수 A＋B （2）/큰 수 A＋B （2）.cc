#include <bits/stdc++.h>
#include <unordered_set>
#define PII pair<int,int>
using namespace std;
typedef long long ll;

string s1, s2;

string add(string a, string b) {
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    if (a.size() < b.size()) swap(a, b);

    int len = a.size() - b.size();
    for (int i = 0; i < len; i++) b += '0';

    string res = "";
    
    int carry = 0;

    for (int i = 0; i < a.size(); i++) {
        int cur = (a[i] - '0') + (b[i] - '0') + carry;
        carry = cur / 10;
        res += (cur % 10) + '0';
    }

    if (carry) res += '1';

    reverse(res.begin(), res.end());
    return res;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> s1 >> s2;
    cout << add(s1, s2);
    return 0;
}