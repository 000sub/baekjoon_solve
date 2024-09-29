#include <bits/stdc++.h>

#define PII pair<int,int>
using namespace std;
typedef long long ll;

int N, M,s,e;

vector<PII> adjs[10001];
bool visited[10001];
constexpr int INF = 1e9;

bool bfs(int cost) {
	memset(visited, false, sizeof(visited));
	queue<int> q;
	q.push(s);
	visited[s] = true;

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		if (cur == e) return true;

		for (PII& p : adjs[cur]) {
			if (!visited[p.first] && p.second >= cost) {
				visited[p.first] = true;
				q.push(p.first);
			}
		}
	}

	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M;
	for (int i = 0,a,b,c; i < M; i++) {
		cin >> a >> b >> c;
		adjs[a].push_back({ b, c });
		adjs[b].push_back({ a, c });
	}
	cin >> s >> e;

	int lo = 0, hi = 1e9;
	while (lo <= hi) {
		int mid = (lo + hi) / 2;
		if (bfs(mid)) lo = mid + 1;
		else hi = mid - 1;
	}

	cout << hi;
	return 0;
}