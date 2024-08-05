#include <bits/stdc++.h>

#define PII pair<int,int>
#define PFF pair<float, float>

using namespace std;
typedef long long ll;

int g;
vector<int> v;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> g;

    int lo = 1, hi = 1;

    while (1) {
        int val = hi * hi - lo * lo;
        if (hi - lo == 1 && val > g) break;


        if (val > g) lo++;
        else if (val == g) {
            v.push_back(hi);
            hi++;
        }
        else hi++;
    }

    if (v.empty()) cout << -1;
    else {
        for (int i : v) cout << i << '\n';
    }

    return 0;
}