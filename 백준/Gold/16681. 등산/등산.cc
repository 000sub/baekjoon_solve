#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <vector>
#include <cmath>

#define PII pair<ll, int>
typedef long long ll;
using namespace std;

const ll INF = 1e12;
ll N, M, D, E;
ll dist[2][100002];
ll H[100001];
vector<PII> graph[100001];

void dijkstra(int idx, int k){
	priority_queue<PII, vector<PII>, greater<PII>> pq;
	
	for (int i=1; i<=N; i++){
		dist[idx][i] = INF;
	}
	
	dist[idx][k] = 0;
	pq.push(make_pair(dist[idx][k], k));
	
	while (!pq.empty()){
		ll cost = pq.top().first;
		int pos = pq.top().second;
		pq.pop();
		
		if (dist[idx][pos] < cost) continue;
		
		for (auto& p : graph[pos]){
			if (H[p.first] > H[pos] && dist[idx][p.first] > cost + p.second){
				dist[idx][p.first] = cost + p.second;
				pq.push(make_pair(dist[idx][p.first], p.first));
			}
		}
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>N>>M>>D>>E;
	
	for (int i=1; i<=N; i++) cin>>H[i];
	
	ll a,b,c;
	for (int i=0; i<M; i++){
		cin>>a>>b>>c;
		graph[a].emplace_back(b,c);
		graph[b].emplace_back(a,c);
	}
	
	dijkstra(0, 1);
	dijkstra(1, N);
	
	ll ans = -1e12;
	
	for (int i=2; i<=N-1; i++){
		if (dist[0][i] == INF || dist[1][i] == INF) continue;
		
		ans = max(ans, H[i] * E - (dist[0][i] + dist[1][i]) * D);
	}
	
	if (ans == -1e12) cout<<"Impossible"<<'\n';
	else cout<<ans<<'\n';

	return 0;
}