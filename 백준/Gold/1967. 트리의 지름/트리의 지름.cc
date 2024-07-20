#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cstring>
#define PII pair<int,int>

using namespace std;

int n, ans = 0;
vector<PII> graph[10001];
bool visited[10001];

void dfs(int cur, int dist) {
	visited[cur] = true;
	ans = max(ans, dist);
	
	for (auto& p: graph[cur]) {
		if (!visited[p.first]) {
			dfs(p.first, p.second+dist);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	
	cin>>n;
	int a,b,c;
	
	for (int i=0; i<n-1; i++) {
		cin>>a>>b>>c;
		
		graph[a].push_back({b,c});
		graph[b].push_back({a,c});
	}
	
	for (int i=1; i<=n; i++) {
		memset(visited, 0, sizeof(visited));
		dfs(i, 0);
	}
	
	cout<<ans;

	return 0;
}
