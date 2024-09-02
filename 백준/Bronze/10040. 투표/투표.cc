#include <bits/stdc++.h>

#define PII pair<int,int>
#define PIII pair<int,PII>

using namespace std;
typedef long long ll;

int N, M;
int A[1001], cnt[1001];

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> N >> M;
    for (int i = 0; i < N; i++) cin >> A[i];

    for (int i = 0, hi; i < M; i++) {
        cin >> hi;
        for (int j = 0; j < N; j++) {
            if (hi >= A[j]) {
                cnt[j]++;
                break;
            }
        }
    }

    int maxCnt = 0;
    int maxIdx = -1;

    for (int i = 0; i < N; i++) {
        if (maxCnt < cnt[i]) {
            maxCnt = cnt[i];
            maxIdx = i;
        }
    }
    cout << maxIdx + 1;

    return 0;
}