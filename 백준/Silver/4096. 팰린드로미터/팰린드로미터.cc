#include <bits/stdc++.h>

#define PII pair<int,int>
#define PIII pair<int,PII>

using namespace std;
typedef long long ll;

string s;

bool isPal() {
    int N = s.size();
    for (int i = 0; i < N / 2; i++) {
        if (s[i] != s[N - 1 - i]) return false;
    }
    return true;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    while (true) {
        cin >> s;
        if (s == "0") break;
        int cnt = 0;
        while (!isPal()) {
            for (int i = s.size() - 1; i >= 0; i--) {
                if (s[i] == '9') s[i] = '0';
                else {
                    s[i] = s[i] + 1;
                    break;
                }
            }
            cnt++;
        }
        cout << cnt << '\n';
    }

    return 0;
}