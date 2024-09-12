#include <bits/stdc++.h>

#define PII pair<int,int>
#define PIII pair<int,PII>

using namespace std;
typedef long long ll;

int n;
ll arr[100001];

ll gcd(ll a, ll b) {
    return a % b == 0 ? b : gcd(b, a % b);
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n;
    for (int i = 0; i < n-2; i++) cin >> arr[i];
    for (int i = 1; i < n-2; i++) {
        arr[i] = arr[i] * arr[i-1] / gcd(arr[i], arr[i - 1]);
    }

    cout << arr[n - 3];
    return 0;
}