#include <bits/stdc++.h>

#define PII pair<int,int>
#define PIII pair<int,PII>

using namespace std;
typedef long long ll;

int N;
PII arr[101];
int dp[101], D[101];

int binSearch(int x, int size) {
    int lo = 0, hi = size-1;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        if (D[mid] > x) {
            hi = mid - 1;
        }
        else lo++;
    }
    return lo;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++) cin >> arr[i].first >> arr[i].second;
    fill(D, D + N, 1e9);

    sort(arr, arr + N);
    for (int i = 0; i < N; i++) {
        int idx = binSearch(arr[i].second, i);
        dp[i] = idx + 1;
        D[idx] = arr[i].second;
    }

    int maxLen = 0;
    for (int i = 0; i < N; i++) maxLen = max(maxLen, dp[i]);
    cout << N - maxLen;
    return 0;
}