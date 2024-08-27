#include <bits/stdc++.h>

#define PII pair<int,int>
#define PIII pair<int,PII>

using namespace std;
typedef long long ll;

int n, m;
int indegree[1001], result[1001];
bool visited[1001];
vector<int> adjList[1001];


int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> n >> m;
	int len, a, b;
	for (int i = 0; i < m; i++) {
		cin >> len >> a;
		for (int j = 0; j < len - 1; j++) {
			cin >> b;
			indegree[b]++;
			adjList[a].push_back(b);
			a = b;
		}
	}

	queue<int> q;

	for (int i = 1; i <= n; i++) {
		if (indegree[i] == 0) q.push(i);
	}

	for (int i = 1; i <= n; i++) {
		if (q.empty()) {
			cout << 0;
			return 0;
		}

		int cur = q.front();
		q.pop();

		for (int next : adjList[cur]) {
			if (--indegree[next]==0) q.push(next);
		}

		result[i] = cur;
	}

	for (int i = 1; i <= n; i++) {
		cout << result[i] << '\n';
	}


	return 0;
}