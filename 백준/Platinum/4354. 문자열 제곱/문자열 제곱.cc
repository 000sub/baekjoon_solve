//kmp 사용

#include <bits/stdc++.h>

#define PII pair<int,int>
#define PIII pair<int,PII>

using namespace std;
typedef long long ll;

string s;
int fail[1000001];

void build() {
    for (int i = 1, j = 0; i < s.size(); i++) {
        while (j > 0 && s[i] != s[j]) j = fail[j - 1];
        if (s[i] == s[j]) fail[i] = ++j;
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    while (cin >> s) {
        if (s == ".") break;
        int N = s.size();
        build();

        //p = N/(N-fail[N-1])
        int div = N - fail[N - 1];
        int ans = (N % div) ? 1 : N / div;
        cout << ans << '\n';
        memset(fail, 0, sizeof(fail));
    }
    return 0;
}