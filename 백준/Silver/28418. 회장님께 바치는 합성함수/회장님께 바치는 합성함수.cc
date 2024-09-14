#include <bits/stdc++.h>

#define PII pair<int,int>
#define PIII pair<int,PII>

using namespace std;
typedef long long ll;

int a, b, c, d, e;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> a >> b >> c >> d >> e;

    string answer;

    if (a * d * d - a * d == 0) {
        if (2 * a * d * e != 0) cout << "Remember my character";
        else if (a * e * e + b * e + c - c * d - e == 0) cout << "Nice";
        else cout<< "Head on";
        return 0;
    }

    int D = (2 * a * d * e) * (2 * a * d * e) - 4 * (a * d * d - a * d) * (a * e * e + b * e + c - c*d - e);

    if (D > 0) answer = "Go ahead";
    else if (D == 0) answer = "Remember my character";
    else answer = "Head on";


    cout << answer;
    return 0;
}