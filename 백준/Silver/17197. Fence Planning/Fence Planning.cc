#include <bits/stdc++.h>

#define PII pair<int,int>
#define PIII pair<int,PII>

using namespace std;
typedef long long ll;

typedef struct Square {
	int x1, x2, y1, y2;
} Square;

int n, m;
vector<Square> v;
int parent[100001];

int Find(int x) {
	if (parent[x] == x) return x;
	return parent[x] = Find(parent[x]);
}

void Union(int x, int y) {
	x = Find(x);
	y = Find(y);

	if (x > y) parent[x] = y;
	else parent[y] = x;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++) parent[i] = i;

	int a, b;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		v.push_back({ a,a,b,b });
	}

	for (int i = 0; i < m; i++) {
		cin >> a >> b;

		a--; b--;

		a = Find(a);
		b = Find(b);

		Square temp = {
				min(v[b].x1, v[a].x1),
				max(v[b].x2, v[a].x2),
				min(v[b].y1, v[a].y1),
				max(v[b].y2, v[a].y2)
		};

		if (a > b) v[b] = temp;
		else v[a] = temp;
		
		Union(a, b);
	}

	int ans = 1e9;

	for (int i = 0; i < n; i++) {
		if (i != parent[i]) continue;
		ans = min(ans, 2 * (v[i].y2 - v[i].y1 + v[i].x2 - v[i].x1));
	}

	cout << ans;
	return 0;
}