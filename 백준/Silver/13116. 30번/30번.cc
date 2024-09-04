#include <bits/stdc++.h>

#define PII pair<int,int>
#define PIII pair<int,PII>

using namespace std;
typedef long long ll;


int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T, a, b;
    cin >> T;
    while (T--) {
        cin >> a >> b;
        while (a != b) a > b ? a >>= 1 : b >>= 1;
        cout << 10 * a << '\n';
    }
    return 0;
}