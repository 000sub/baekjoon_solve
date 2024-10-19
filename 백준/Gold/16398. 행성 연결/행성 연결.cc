#include <bits/stdc++.h>

#define PII pair<int,int>
using namespace std;
typedef long long ll;

int N;
int parent[1001];

int Find(int x) {
    if (parent[x] == x) return x;
    return parent[x] = Find(parent[x]);
}

void Union(int x, int y) {
    x = Find(x);
    y = Find(y);
    if (x < y) parent[y] = x;
    else parent[x] = y;
}


struct Node {
    int cost;
    int x;
    int y;
};
vector<Node> v;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N;

    for (int i = 1; i <= N; i++) parent[i] = i;

    for (int i = 1, cost; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> cost;
            if (i == j) continue;
            v.push_back({ cost, i, j });
        }
    }
    

    sort(v.begin(), v.end(), [](Node& a, Node& b) {return a.cost < b.cost; });

    ll ans = 0;

    for (int i = 0; i < v.size(); i++) {
        if (Find(v[i].x) != Find(v[i].y)) {
            ans += v[i].cost;
            Union(v[i].x, v[i].y);
        }
    }

    cout << ans;

    return 0;
}