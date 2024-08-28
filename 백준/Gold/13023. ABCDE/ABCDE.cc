#include <bits/stdc++.h>

#define PII pair<int,int>
#define PIII pair<int,PII>

using namespace std;
typedef long long ll;

int N, M;
vector<int> adj[2001];
bool visited[2001];

int dfs(int x, int depth) {
	int ret = depth;
	if (ret >= 5) return ret;
	visited[x] = true;

	for (int next : adj[x]) {
		if (!visited[next]) ret = max(ret, dfs(next, depth + 1));
	}

	visited[x] = false;
	return ret;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	int a, b;
	while (M--) {
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	for (int i = 0; i < N; i++) {
		memset(visited, false, sizeof(visited));
		if (dfs(i, 1) >= 5) {
			cout << 1;
			return 0;
		}
	}
	cout << 0;
	return 0;
}