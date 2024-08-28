#include <bits/stdc++.h>

#define PII pair<int,int>
#define PIII pair<int,PII>

using namespace std;
typedef long long ll;

int N;
int A[501], result[501], indegree[501];
vector<int> adj[501];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;

	int t, from;
	for (int i = 1; i <= N; i++) {
		cin >> t;
		A[i] = t;
		while (cin >> from) {
			if (from == -1) break;
			adj[from].push_back(i);
			indegree[i]++;
		}
	}

	queue<int> q;
	for (int i = 1; i <= N; i++) if (indegree[i] == 0) 
		q.push(i), result[i] = A[i];

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		for (int next : adj[cur]) {
			result[next] = max(result[next], result[cur] + A[next]);
			if (--indegree[next]==0) q.push(next);
		}
	}

	for (int i = 1; i <= N; i++) cout << result[i] << '\n';
	return 0;
}