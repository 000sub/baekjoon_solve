#include <bits/stdc++.h>

#define PII pair<int,int>
#define PIII pair<int,PII>

using namespace std;
typedef long long ll;

int N;
PII arr[100001], D[100001];
int dp[100001];
map<int, int> m;

int binSearch(int x, int size) {
    int lo = 0, hi = size-1;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        if (D[mid].second > x) {
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
    for (int i = 0; i < N; i++) cin >> arr[i].first >> arr[i].second, D[i] = { 1e9, 1e9 };
    sort(arr, arr + N);
    for (int i = 0; i < N; i++) {
        int idx = binSearch(arr[i].second, i);
        dp[i] = idx + 1;
        D[idx] = arr[i];
    }

    int maxLen = 0;
    for (int i = 0; i < N; i++) maxLen = max(maxLen, dp[i]);
    int ansIdx = maxLen;
    vector<int> ansV;
    for (int i = N - 1; i >= 0; i--) {
        if (ansIdx == dp[i]) ansIdx--;
        else ansV.push_back(arr[i].first);
    }
    reverse(ansV.begin(), ansV.end());
    cout << N - maxLen << '\n';
    for (int i : ansV) cout << i << '\n';
    return 0;
}