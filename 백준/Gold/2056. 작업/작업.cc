#include <bits/stdc++.h>
#include <cstdio>
#define PII pair<int,int>
#define PIII pair<int,PII>

using namespace std;
typedef long long ll;

int n;
vector<int> adj[10001];
int T[10001], indegree[10001], result[10001];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	for (int i = 1, len, k; i <= n; i++) {
		cin >> T[i] >> len;

		while (len--) {
			cin >> k;
			adj[i].push_back(k);
			indegree[k]++;
		}
	}

	queue<int> q;
	for (int i = 1; i <= n; i++) if (indegree[i] == 0) result[i] = T[i], q.push(i);

	for (int i = 1; i <= n; i++) {
		int cur = q.front();
		q.pop();

		for (int next : adj[cur]) {
			result[next] = max(result[next], result[cur] + T[next]);
			if (--indegree[next] == 0) q.push(next);
		}
	}


	int ans = 0;
	for (int i = 1; i <= n; i++) ans = max(ans, result[i]);
	cout << ans;
	
	return 0;
}