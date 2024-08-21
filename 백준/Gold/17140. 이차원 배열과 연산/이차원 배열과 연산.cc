#include <bits/stdc++.h>
#define PII pair<int,int>

using namespace std;
typedef long long ll;

int arr[101][101];
int cnt[101];
int R, C, K;

bool cmp(PII& a, PII& b) {
    if (a.second != b.second) return a.second < b.second;
    return a.first < b.first;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> R >> C >> K;
    int rSize = 3, cSize = 3;
    for (int i = 0; i < 3; i++) for (int j = 0; j < 3; j++) cin>>arr[i][j];
    for (int t = 0; t <= 100; t++) {
        if (arr[R-1][C-1] == K) {
            cout << t;
            return 0;
        }
        if (rSize >= cSize) {
            for (int i = 0; i < rSize; i++) {
                vector<PII> v;
                memset(cnt, 0, sizeof(cnt));
                int j = 0, lastValidIdx;
                for (int j = 0; j < 100; j++) cnt[arr[i][j]]++;
            
                for (int k = 1; k <= 100; k++) {
                    if (cnt[k]) v.emplace_back(k, cnt[k]);
                }
                sort(v.begin(), v.end(), cmp);
                for (int k = 0; k < v.size()*2; k+=2) {
                    arr[i][k] = v[k/2].first;
                    arr[i][k + 1] = v[k/2].second;
                }
                for (int k = v.size() * 2; k < cSize; k++) arr[i][k] = 0;
            }

            for (int i = 0, j; i < rSize; i++) {
                for (j = 0; j < 100; j++) {
                    if (arr[i][j] == 0) break;
                }
                cSize = max(cSize, j);
            }
        }
        else {
            for (int i = 0; i < cSize; i++) {
                vector<PII> v;
                memset(cnt, 0, sizeof(cnt));
                for (int j = 0; j < 100; j++) cnt[arr[j][i]]++;
                for (int k = 1; k <= 100; k++) {
                    if (cnt[k]) v.emplace_back(k, cnt[k]);
                }
                sort(v.begin(), v.end(), cmp);
                for (int k = 0; k < v.size()*2; k += 2) {
                    arr[k][i] = v[k / 2].first;
                    arr[k+1][i] = v[k / 2].second;
                }
                for (int k = v.size() * 2; k < cSize; k++) arr[k][i] = 0;
            }

            for (int i = 0, j; i < cSize; i++) {
                for (j = 0; j < 100; j++) {
                    if (arr[j][i] == 0) break;
                }
                rSize = max(rSize, j);
            }
        }
    }
    cout << -1;
    return 0;
}