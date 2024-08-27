#include <bits/stdc++.h>

#define PII pair<int,int>
#define PIII pair<int,PII>

using namespace std;
typedef long long ll;

int n, k, T, a,b, W;
int indegree[1001], result[1001], D[1001];
vector<int> adjList[1001];


int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> T;

	while (T--) {
		cin >> n >> k;
		for (int i = 1; i <= n; i++) cin >> D[i];

		for (int i = 0; i < k; i++) {
			cin >> a >> b;
			indegree[b]++;
			adjList[a].push_back(b);
		}
		cin >> W;

		queue<int> q;
		for (int i = 1; i <= n; i++) {
			if (indegree[i] == 0) {
				q.push(i);
				result[i] = D[i];
			}
		}

		bool flag = false;

		for (int i = 1; i <= n; i++) {
			int cur = q.front();
			q.pop();

			for (int next : adjList[cur]) {
				result[next] = max(result[next], result[cur] + D[next]);
				if (--indegree[next] == 0) {
					q.push(next);
					if (next == W) {
						flag = true;
						break;
					}
				}
			}

			if (flag) break;
		}

		cout << result[W] << '\n';

		for (int i = 1; i <= n; i++) adjList[i].clear();
		memset(indegree, 0, sizeof(indegree));
		memset(result, 0, sizeof(result));
	}


	return 0;
}