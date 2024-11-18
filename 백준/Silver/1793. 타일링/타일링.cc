#include <bits/stdc++.h>
#include <unordered_set>
#define PII pair<int,int>
using namespace std;
typedef long long ll;

int N;
string dp[251] = { "1","1","3" };

string add(string a, string b) {
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    if (a.size() < b.size()) swap(a, b);

    for (int i = 0; i < a.size() - b.size(); i++) b += "0";

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

    for (int i = 3; i <= 250; i++) {
        dp[i] = add(dp[i - 1], dp[i - 2]);
        dp[i] = add(dp[i], dp[i - 2]);
    }
    
    while (cin>>N) {
        cout << dp[N] << '\n';
    }
    return 0;
}