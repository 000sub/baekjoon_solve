#include <bits/stdc++.h>

#define PII pair<int,int>
#define PFF pair<float, float>
#define MAX 1000001
using namespace std;
typedef long long ll;

int n;
int arr[MAX], dp[MAX], A[MAX];
vector<int> v;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];
    fill(A, A + n, 1e9);

    for (int i = 0; i < n; i++) {
        int idx = lower_bound(A, A + i, arr[i]) - A;
        dp[i] = idx + 1;
        A[idx] = arr[i];
    }

    int ans = 0, arrIdx = -1;

    for (int i = 0; i < n; i++) {
        if (ans < dp[i]) {
            ans = dp[i];
            arrIdx = i;
        }
    }

    
    v.push_back(arr[arrIdx]);

    int lisIdx = ans - 1;
    for (int i = arrIdx - 1; i >= 0; i--) {
        if (dp[i] == lisIdx) {
            v.push_back(arr[i]);
            lisIdx--;
        }

        if (lisIdx == 0) break;
    }

    reverse(v.begin(), v.end());

    cout << ans << '\n';
    for (int k : v) {
        cout << k << " ";
    }
    cout << '\n';
    

    return 0;
}