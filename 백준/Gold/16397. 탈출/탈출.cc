#include <bits/stdc++.h>
#include <unordered_set>
#define PII pair<int,int>
using namespace std;
typedef long long ll;

int N, T, G;
bool visited[100001];

int bfs() {
    queue<PII> q;

    q.push({ N, 0 });
    visited[N] = true;

    while (!q.empty()) {
        auto [cur, cnt] = q.front();
        q.pop();

        if (cnt > T) continue;
        if (cur == G) return cnt;

        if (!visited[cur + 1]) {
            visited[cur + 1] = true;
            q.push({ cur + 1, cnt + 1 });
        }

        int temp = cur*2 - pow(10, (int)log10(cur*2));

        if (cur > 0 && cur < 50000 && !visited[temp]) {
            visited[temp] = true;
            q.push({ temp, cnt + 1 });
        }
    }

    return -1;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N >> T >> G;

    int res = bfs();

    res == -1 ? cout << "ANG" : cout << res;

    return 0;
}