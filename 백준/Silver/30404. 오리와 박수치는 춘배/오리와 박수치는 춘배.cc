#include <bits/stdc++.h>

#define PII pair<int,int>
#define PIII pair<int,PII>

using namespace std;
typedef long long ll;

int n, k;
int arr[100001];

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> k;
    for (int i=0; i<n; i++) cin >> arr[i];

    int ans = 1, last = arr[0] + k;
    for (int i = 1; i < n; i++) {
        if (arr[i] > last) {
            last = arr[i] + k;
            ans++;
        }
    }
    cout << ans;
    return 0;
}