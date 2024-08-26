#include <bits/stdc++.h>

#define PII pair<int,int>
#define PIII pair<int,PII>

using namespace std;
typedef long long ll;

int n,m;
vector<int> adjList[32001];
vector<int> v;
bool visited[32001];

void DFS(int x) {
	visited[x] = true;

	for (int next : adjList[x]) {
		if (!visited[next]) DFS(next);
	}

	v.push_back(x);
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;

	int a, b;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		adjList[a].push_back(b);
	}

	for (int i = 1; i <= n; i++) {
		if (!visited[i]) DFS(i);
	}

	reverse(v.begin(), v.end());
	for (int i : v) {
		cout << i << " ";
	}
	return 0;
}