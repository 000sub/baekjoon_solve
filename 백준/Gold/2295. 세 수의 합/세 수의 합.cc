#include <bits/stdc++.h>

#define PII pair<int,int>

typedef long long ll;
using namespace std;

int n, ans = 0;
int arr[1001];
vector<int> v;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < n-1; i++) {
        for (int j = i; j < n; j++) {
            v.push_back(arr[i] + arr[j]);
        }
    }

    sort(arr, arr + n);
    sort(v.begin(), v.end());

    for (int i = n - 1; i >= 1; i--) {
        for (int j = 0; j < i; j++) {
            if (binary_search(v.begin(), v.end(), arr[i] - arr[j])) {
                ans = max(ans, arr[i]);
            }
        }
    }

    cout << ans;
    return 0;
}