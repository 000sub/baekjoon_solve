#include <bits/stdc++.h>

#define PII pair<int,int>
#define PIII pair<int,PII>

using namespace std;
typedef long long ll;

int N, M;
int dist[101][101];

constexpr int INF = 1e5;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;
    for (int i = 1; i <= N; i++) for (int j = 1; j <= N; j++) dist[i][j] = (i == j) ? 0 : INF;

    for (int i = 0, a, b; i < M; i++) {
        cin >> a >> b;
        dist[a][b] = 1, dist[b][a] = 1;
    }

    for (int k = 1; k <= N; k++) {
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    int s, e, sum = 1e9;
    for (int i = 1; i <= N-1; i++) {
        for (int j = i + 1; j <= N; j++) {
            int curSum = 0;
            for (int k = 1; k <= N; k++) curSum += min(dist[i][k], dist[j][k]);
            if (curSum < sum) {
                sum = curSum;
                s = i;
                e = j;
            }
        }
    }

    cout << s << " " << e << " " << sum*2;
    return 0;
}