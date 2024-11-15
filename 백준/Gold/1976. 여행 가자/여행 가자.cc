#include <bits/stdc++.h>
#include <unordered_set>
#define PII pair<int,int>
using namespace std;
typedef long long ll;

int N, M;
int parent[201];
vector<int> route;

int Find(int x) {
    if (parent[x] == x) return x;
    return parent[x] = Find(parent[x]);
}

void Union(int x, int y) {
    x = Find(x);
    y = Find(y);

    if (x < y) parent[x] = y;
    else parent[y] = x;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N >> M;

    for (int i = 1; i <= N; i++) parent[i] = i;

    for (int i = 1, temp; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> temp;
            if (temp == 1) Union(i, j);
        }
    }

    for (int i = 0, temp; i < M; i++) {
        cin >> temp;
        route.push_back(temp);
    }

    for (int i = 0; i < M - 1; i++) {
        if (Find(route[i]) != Find(route[i+1])) {
            cout << "NO";
            return 0;
        }
    }

    cout << "YES";
    return 0;
}