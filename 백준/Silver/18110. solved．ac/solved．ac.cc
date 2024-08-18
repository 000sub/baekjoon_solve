#include <bits/stdc++.h>

#define PII pair<int,int>
#define PFF pair<float, float>

using namespace std;
typedef long long ll;

int arr[300000];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, sum = 0;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];

    if (n == 0) {
        cout << 0;
        return 0;
    }

    float _dn = (float) n / 100 * 15;
    int dn = round(_dn);

    sort(arr, arr + n);

    for (int i = dn; i < n - dn; i++) sum += arr[i];

    float _avg = (float)sum / (n - 2 * dn);
    int avg = round(_avg);

    cout << avg;

    return 0;
}