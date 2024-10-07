#include <bits/stdc++.h>

#define PII pair<int,int>
using namespace std;
typedef long long ll;

int N, M;
vector<PII> adjs[1001];
int dist[1001];
int prev_pos[1001];
const int INF = 1e9;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 0, a, b, c; i < M; i++) {
		cin >> a >> b >> c;
		adjs[a].push_back({ c, b });
	}

	int s, e;
	cin >> s >> e;

	for (int i = 1; i <= N; i++) dist[i] = INF;
	priority_queue<PII, vector<PII>, greater<PII>> pq;
	pq.push({ 0, s });
	dist[s] = 0;
	while (!pq.empty()) {
		auto [cost, pos] = pq.top();
		pq.pop();

		if (cost > dist[pos]) continue;

		for (PII& p : adjs[pos]) {
			int nCost = cost + p.first;
			if (nCost < dist[p.second]) {
				dist[p.second] = nCost;
				prev_pos[p.second] = pos;
				pq.push({ dist[p.second], p.second });
			}
		}
	}

	
	vector<int> route;
	int cnt = 0;
	cout << dist[e] << '\n';
	while (e != s) {
		cnt++;
		route.push_back(e);
		e = prev_pos[e];
	}
	cnt++;
	route.push_back(e);
	
	cout << cnt << '\n';
	for (int i = route.size() - 1; i >= 0; i--) cout << route[i] << ' ';
	return 0;
}