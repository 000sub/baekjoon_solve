#include <iostream>
#include <algorithm>
#include <queue>
#define INF 1000000000
#define PII pair<int,int>
using namespace std;

int n, m, x;
vector<PII> graph[1001], rev_graph[1001];
int dist[1001], dist2[1001];
priority_queue<PII, vector<PII>, greater<PII>> pq;
void dijkstra(bool flag, int d[]){
	pq = priority_queue<PII, vector<PII>, greater<PII>>();
	fill(d, d+n+1, INF);
	pq.push(PII(0, x));
	d[x] = 0;
	
	auto& cur_graph = flag ? graph : rev_graph;
	while (!pq.empty()){
		int curcost = pq.top().first;
		int curpos = pq.top().second;
		pq.pop();
		
		if (curcost > d[curpos]) continue;
		for (auto& p: cur_graph[curpos]){
			if (d[p.second] > curcost + p.first){
				d[p.second] = curcost + p.first;
				pq.push(PII(d[p.second], p.second));
			}
		}
	}
}

int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin>>n>>m>>x;
	
	int a,b,c;
	for (int i=0; i<m; i++){
		cin>>a>>b>>c;
		graph[a].emplace_back(c, b);
		rev_graph[b].emplace_back(c,a);
	}
	
	int ans =0;
	
	dijkstra(true, dist); dijkstra(false, dist2); 
	for (int i=1; i<=n; i++){
		if (ans < dist[i] + dist2[i]) ans = dist[i] + dist2[i];
	}
	cout<<ans<<"\n";

	return 0;
}