#include <bits/stdc++.h>

#define PII pair<int,int>
using namespace std;
typedef long long ll;

int N, K, ans = 1e9;
int dist[11][11];
bool visited[11];

void dfs(int cur, int cnt, int sum) {
    if (cnt == N) {
        ans = min(ans, sum);
        return;
    }

    for (int i = 0; i < N; i++) {
        if (!visited[i]) {
            visited[i] = true;
            dfs(i, cnt + 1, sum + dist[cur][i]);
            visited[i] = false;
        }
    }
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> dist[i][j];
        }
    }

    for (int k = 0; k < N; k++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    visited[K] = true;
    dfs(K, 1, 0);

    cout << ans;

    
    return 0;
}