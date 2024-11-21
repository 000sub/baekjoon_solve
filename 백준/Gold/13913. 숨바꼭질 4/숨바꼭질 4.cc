#include <bits/stdc++.h>
#include <unordered_set>
#define PII pair<int,int>
using namespace std;
typedef long long ll;

int dist[100001], prevPos[100001];
bool visited[100001];
int N, K, ans = 0;
int INF = 1e9;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> N >> K;

    if (N == K) {
        cout << 0 << '\n' << N;
        return 0;
    }

    queue<int> q;
    q.push(N);
    visited[N] = true;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        if (cur == K) {
            ans = dist[cur];
            break;
        }

        int next[3] = {cur + 1, cur - 1, cur * 2};

        for (int d = 0; d < 3; d++) {
            int nextPos = next[d];

            if (nextPos >= 0 && nextPos <= 100000 && !visited[nextPos]) {
                visited[nextPos] = true;
                q.push(nextPos);
                dist[nextPos] = dist[cur] + 1;
                prevPos[nextPos] = cur;
            }
        }
    }

    vector<int> route;
    
    while (K != N) {
        route.push_back(K);
        K = prevPos[K];
    }
    route.push_back(N);

    cout << ans << '\n';
    for (int i = ans; i >= 0; i--) cout << route[i] << " ";

    return 0;
}