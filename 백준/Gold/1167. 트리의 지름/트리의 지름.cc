#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cstring>
#define PII pair<int,int>

using namespace std;

int n, ans = 0, node = -1;
vector<PII> graph[100001];
bool visited[100001];

void dfs(int cur, int dist) {
	visited[cur] = true;
	if (ans < dist) {
		node = cur;
		ans = dist;
	}
	
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
	
	for (int i=0; i<n; i++) {
		cin>>a;
		
		while (1) {
			cin>>b;
			if (b == -1) break;
			cin>>c;
			
			graph[a].push_back({b,c});
			graph[b].push_back({a,c});
		}
	}
	
	dfs(1,0);
	memset(visited, 0, sizeof(visited));
	dfs(node, 0);
	
	cout<<ans;

	return 0;
}
