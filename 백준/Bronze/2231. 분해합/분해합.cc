#include <bits/stdc++.h>

#define PII pair<int,int>
#define PFF pair<float, float>

using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        int sum = i;
        int temp = i;
        while (temp > 0) {
            sum += temp % 10;
            temp /= 10;
        }

        if (sum == n) {
            cout << i;
            return 0;
        }
    }

    cout << 0;
    return 0;
}