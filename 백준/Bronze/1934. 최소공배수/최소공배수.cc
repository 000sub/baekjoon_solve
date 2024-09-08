#include <bits/stdc++.h>

#define PII pair<int,int>
#define PIII pair<int,PII>

using namespace std;
typedef long long ll;

int T, a, b;

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> T;
    while (T--) {
        cin >> a >> b;
        cout << a * b / gcd(a, b) << '\n';
    }
    
    return 0;
}