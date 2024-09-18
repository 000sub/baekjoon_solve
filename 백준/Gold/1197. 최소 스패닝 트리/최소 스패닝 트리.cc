#include <bits/stdc++.h>

#define PII pair<int,int>
#define PIII pair<int,PII>

using namespace std;
typedef long long ll;

int V, E;
int parent[10001];
typedef struct Node {
    int s;
    int e;
    int cost;

    bool operator<(const Node& other) const {
        return cost < other.cost;
    }
};

vector<Node> v;

int Find(int x) {
    if (parent[x] == x) return x;
    return parent[x] = Find(parent[x]);
}

void Union(int x, int y) {
    x = Find(x), y = Find(y);

    if (x < y) parent[y] = x;
    else parent[x] = y;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> V >> E;
    for (int i = 1; i <= V; i++) parent[i] = i;
    for (int i = 0,a,b,c; i < E; i++) {
        cin >> a >> b >> c;
        v.push_back({ a,b,c });
    }
    sort(v.begin(), v.end());

    int sum = 0;
    for (int i = 0; i < E; i++) {
        if (Find(v[i].s) != Find(v[i].e)) {
            sum += v[i].cost;
            Union(v[i].s, v[i].e);
        }
    }

    cout << sum;

   
    return 0;
}