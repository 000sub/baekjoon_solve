#include <bits/stdc++.h>

#define PII pair<int,int>
#define PIII pair<int,PII>

using namespace std;
typedef long long ll;

int dp[1000001];
int N;
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> N;

    int maxN = 1;
    for (int i = 0, a; i < N; i++) {
        cin >> a;
        dp[a] = dp[a - 1] + 1;
        maxN = max(maxN, dp[a]);
    }
    
    cout << N - maxN;
    return 0;
}