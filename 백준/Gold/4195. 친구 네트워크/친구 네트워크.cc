#include <bits/stdc++.h>

#define PII pair<int,int>
using namespace std;
typedef long long ll;

int T, F;
int parent[200001], network_size[200001];
unordered_map<string, int> userids;

int Find(int x) {
	if (parent[x] == x) return x;
	return parent[x] = Find(parent[x]);
}

void Union(int x, int y) {
	x = Find(x);
	y = Find(y);

	if (x < y) {
		parent[y] = x;
		network_size[x] += network_size[y];
	}
	else if (x > y) {
		parent[x] = y;
		network_size[y] += network_size[x];
	}
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> T;
	string s1, s2;
	while (T--) {
		cin >> F;
		for (int i = 0; i < 2*F; i++) parent[i] = i, network_size[i] = 1;
		int idx = 0, ans = 0;
		for (int i = 0; i < F; i++) {
			cin >> s1 >> s2;
			if (!userids.count(s1)) userids[s1] = idx++;
			if (!userids.count(s2)) userids[s2] = idx++;

			Union(userids[s1], userids[s2]);
			int key = Find(userids[s1]);
			cout << network_size[parent[key]] << '\n';
		}
	}
	return 0;
}