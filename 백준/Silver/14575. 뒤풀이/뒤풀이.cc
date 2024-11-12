#include <bits/stdc++.h>
#include <unordered_set>
#define PII pair<int,int>
using namespace std;
typedef long long ll;

int N, T, ans = -1;
int L[1001], R[1001];

bool check(int k) {
    int minSum = 0, maxSum = 0;

    for (int i = 0; i < N; i++) {
        if (k < L[i]) return false;
        minSum += L[i];
        maxSum += min(k, R[i]);
    }
    return minSum <= T && T <= maxSum;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N >> T;
    for (int i = 0; i < N; i++) {
        cin >> L[i] >> R[i];
    }

    int lo = 0, hi = 1e9;

    while (lo <= hi) {
        int mid = (lo + hi) / 2;

        if (check(mid)) ans = mid, hi = mid - 1;
        else lo = mid + 1;
    }

    cout << ans;

    return 0;
}