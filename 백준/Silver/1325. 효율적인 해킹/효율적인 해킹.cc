#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
#include <cstring>
#include <cmath>
#include <map>
typedef long long ll;
using namespace std;

vector<int> graph[100001];
bool visited[100001];
int cnt[100001];

int dfs(int s) {
	int res = 1;
	visited[s] = true;
	
	for (int next : graph[s]) {
		if (!visited[next]) {
			res += dfs(next);
		}
	}
	
	return res;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n, m;
	cin>>n>>m;
	
	int a,b;
	int maxCnt = 0;
	
	for (int i=0; i<m; i++) {
		cin>>a>>b;
		graph[b].push_back(a);
	}
	
	for (int i=1; i<=n; i++) {
		memset(visited, 0, sizeof(visited));
		cnt[i]  = dfs(i);
		if (cnt[i] > maxCnt) maxCnt = cnt[i];
	}
	
	for (int i=1; i<=n; i++) {
		if (cnt[i] == maxCnt) cout<<i<<' ';
	}
	cout<<'\n';
}