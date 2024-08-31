#include <bits/stdc++.h>
#define PII pair<int,int>
#define PIII pair<int,PII>

using namespace std;
typedef long long ll;
const int INF = 1e9;

int n, m;
tuple<int, int, int> edges[200001];
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
		for (int i = 0; i < m; i++) parent[i] = i;
		for (int i = 0; i < n; i++) {
			auto &[c, a, b] = edges[i];
			cin >> a >> b >> c;
		}
		sort(edges, edges + n, [](tuple<int, int, int>& a, tuple<int, int, int>& b) {return get<0>(a) < get<0>(b); });

		int ans = 0;
		for (int i = 0; i < n; i++) {
			auto &[c, a, b] = edges[i];
			if (!Union(a, b)) ans += c;
		}
		cout << ans << '\n';
	}
	
	return 0;


}