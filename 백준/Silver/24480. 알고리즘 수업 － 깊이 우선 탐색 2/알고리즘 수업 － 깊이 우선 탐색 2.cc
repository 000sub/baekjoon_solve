#include <bits/stdc++.h>

#define PII pair<int,int>
using namespace std;
typedef long long ll;

int N, M, R, a, b, cnt = 1;
vector<int> adjs[100001];
int dist[100001];

void dfs(int cur) {
    dist[cur] = cnt++;

    for (int next : adjs[cur]) {
        if (dist[next] == 0) dfs(next);
    }
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N >> M >> R;

    while (M--) {
        cin >> a >> b;
        adjs[a].push_back(b);
        adjs[b].push_back(a);
    }

    for (int i = 1; i <= N; i++) sort(adjs[i].begin(), adjs[i].end(), greater<>());
    dfs(R);
    for (int i = 1; i <= N; i++) cout << dist[i] << '\n';


    return 0;
}