#include <bits/stdc++.h>
#define PII pair<int,int>
#define PIII pair<int,PII>

using namespace std;
typedef long long ll;
const int INF = 1e9;

int n, m;
PIII edges[200001];
int parent[200001];

int Find(int x) {
	if (parent[x] == x) return x;
	return parent[x] = Find(parent[x]);
}

bool Union(int x, int y) {
	x = Find(x);
	y = Find(y);

	if (x == y) return false;

	if (x < y) parent[y] = x;
	else parent[x] = y;

	return true;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	while (1) {
		cin >> m >> n;
		if (m == 0 && n == 0) break;
		int totalCost = 0;
		for (int i = 0; i < m; i++) parent[i] = i;
		for (int i = 0, a, b, c; i < n; i++) {
			cin >> a >> b >> c;
			totalCost += c;
			edges[i] = { c, {a,b} };
		}
		sort(edges, edges + n);

		int cnt = 0, minCost = 0;
		for (int i = 0; i < n; i++) {
			int cost = edges[i].first;
			int a = edges[i].second.first;
			int b = edges[i].second.second;

			if (Union(a, b)) {
				cnt++;
				minCost += cost;
			}

			if (cnt == m - 1) break;
		}
		cout << totalCost - minCost << '\n';
	}
	
	return 0;


}