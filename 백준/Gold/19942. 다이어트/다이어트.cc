#include <bits/stdc++.h>

#define PII pair<int,int>
#define PIII pair<int,PII>
using namespace std;
typedef long long ll;

int N;
int mp, mf, ms, mv;

struct Item {
	int p;
	int f;
	int s;
	int v;
	int c;
};

Item items[15];
Item result;
vector<int> v, ansV;
int minCost = 1e9;

bool check() {
	return result.p >= mp && result.f >= mf && result.s >= ms && result.v >= mv;
}

void dfs(int idx) {
	if (check()) {
		if (result.c < minCost) {
			minCost = result.c;
			ansV = v;
		}
		return;
	}

	for (int i = idx; i < N; i++) {
		v.push_back(i);
		result.p += items[i].p;
		result.f += items[i].f;
		result.s += items[i].s;
		result.v += items[i].v;
		result.c += items[i].c;
		dfs(i + 1);
		result.p -= items[i].p;
		result.f -= items[i].f;
		result.s -= items[i].s;
		result.v -= items[i].v;
		result.c -= items[i].c;
		v.pop_back();
	}
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> mp >> mf >> ms >> mv;

	for (int i = 0; i < N; i++) {
		cin >> items[i].p >> items[i].f >> items[i].s >> items[i].v >> items[i].c;
	}

	dfs(0);

	if (minCost == 1e9) {
		cout << -1;
		return 0;
	}

	cout << minCost << '\n';
	for (int i : ansV) cout << i+1 << " ";
	return 0;
}