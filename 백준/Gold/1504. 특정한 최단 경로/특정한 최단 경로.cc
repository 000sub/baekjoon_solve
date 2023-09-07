#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <vector>

#define PII pair<int, int> 

using namespace std;
typedef long long ll;

const int INF = 1e8 * 3;
int N,E;
int u,v;
vector<PII> vec[801];
int dist[801][3];

void dijkstra(int s, int i){
	priority_queue<PII, vector<PII>, greater<PII>> pq;
	for (int k=0; k<=N; k++){
		dist[k][i]  = INF;
	}
	pq.push(PII(0, s));
	dist[s][i] = 0;
	while (!pq.empty()){
		ll curcost = pq.top().first;
		int curpos = pq.top().second;
		pq.pop();
		
		if (dist[curpos][i] < curcost) continue;
		
		for (auto& p : vec[curpos]){
			if (dist[p.first][i] > curcost + p.second){
				dist[p.first][i] = curcost + p.second;
				pq.push(PII(dist[p.first][i], p.first));
			}
		}
	}
	
}
int main(){
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
		
	cin>>N>>E;
	
	int a,b,c;
	for (int i=0; i<E; i++){
		cin>>a>>b>>c;
		vec[a].emplace_back(b,c);
		vec[b].emplace_back(a,c);
	}
	
	
	cin>>u>>v;
	
	dijkstra(1, 0);
	dijkstra(u, 1);
	dijkstra(v, 2);
	
	int ans = INF;
	
	ans = min(ans, dist[u][0] + dist[v][1] + dist[N][2]);
	ans = min(ans, dist[v][0] + dist[N][1] + dist[u][2]);
	
	if (ans == INF) cout<<-1<<'\n';
	else cout<<ans<<'\n';

	return 0;
}