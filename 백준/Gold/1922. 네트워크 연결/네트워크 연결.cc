#include <bits/stdc++.h>

#define PII pair<int,int>
#define PIII pair<int,PII>

using namespace std;
typedef long long ll;

struct cmp {
	bool operator()(PIII& a, PIII& b) {
		return a.first > b.first;
	}
};

int N, M;
int parent[1001];
priority_queue<PIII, vector<PIII>, cmp> pq;


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

bool isFinished() {
	for (int i = 1; i <= N; i++) {
		if (parent[i] != 1) return false;
	}
	return true;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;

	for (int i = 1; i <= N; i++) parent[i] = i;
	int a, b, c;
	while (M--) {
		cin >> a >> b >> c;
		pq.push({ c, {a,b} });
	}

	int ans = 0;
	while (!pq.empty() && !isFinished()) {
		a = pq.top().second.first;
		b = pq.top().second.second;
		c = pq.top().first;
		pq.pop();

		if (Find(a) != Find(b)) {
			Union(a, b);
			ans += c;
		}
	}

	cout << ans;
	return 0;
}