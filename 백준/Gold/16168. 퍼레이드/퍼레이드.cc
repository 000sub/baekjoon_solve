#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#define PII pair<int,int>

using namespace std;
typedef long long ll;

int degree[3001];
int parent[3001];
int v, e, a, b;

int findParent(int x) {
	if (parent[x] != x)
		parent[x] = findParent(parent[x]);
	return parent[x];
}

void unionParent(int x, int y) {
	x = findParent(x);
	y = findParent(y);

	if (x < y) parent[y] = x;
	else parent[x] = y;
}

bool checkSingleComponent() {
	int root = findParent(1);
	for (int i = 1; i <= v; i++) {
		if (findParent(i) != root) return false;
	}

	return true;
}

bool checkEulerTrail() {
	int cnt = 0;

	for (int i = 1; i <= v; i++) {
		if (degree[i] % 2) cnt++;
	}

	return cnt == 0 || cnt == 2;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> v >> e;
	for (int i = 1; i <= v; i++) parent[i] = i;

	for (int i = 0; i < e; i++) {
		cin >> a >> b;
		degree[a]++;
		degree[b]++;
		unionParent(a, b);
	}

	if (checkEulerTrail() && checkSingleComponent()) {
		cout << "YES" << '\n';
	}
	else {
		cout << "NO" << '\n';
	}

	return 0;
}