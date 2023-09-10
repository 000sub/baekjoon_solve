#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <vector>

#define PII pair<int, int>
#define MAX 10001
using namespace std;
typedef long long ll;

const ll INF = 1e14;
int N, M, K;
ll dist[21][MAX];
vector<PII> graph[MAX];

void dijkstra(){
	priority_queue<pair<ll, PII>, vector<pair<ll, PII>>, greater<pair<ll, PII>>> pq;
	
	for (int i=0; i<=K; i++){
		for (int j=1; j<=N; j++){
			dist[i][j] = INF;
		}
	}
	
	dist[K][1] = 0;
	pq.push(make_pair(dist[K][1], PII(1, K)));
	
	while (!pq.empty()){
		ll cost = pq.top().first;
		int pos = pq.top().second.first;
		int pcnt = pq.top().second.second;
		pq.pop();
		
		if (dist[pcnt][pos] < cost) continue;
		
		for (auto& p : graph[pos]){
			if (dist[pcnt][p.first] > cost + p.second){
				dist[pcnt][p.first] = cost + p.second;
				pq.push(make_pair(dist[pcnt][p.first], PII(p.first, pcnt)));
			}
			
			if (pcnt > 0 && dist[pcnt-1][p.first] > cost){
				dist[pcnt-1][p.first] = cost;
				pq.push(make_pair(dist[pcnt-1][p.first], PII(p.first, pcnt-1)));
			}
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>N>>M>>K;
	
	ll a,b,c;
	for (int i=0; i<M; i++){
		cin>>a>>b>>c;
		graph[a].emplace_back(b,c);
		graph[b].emplace_back(a,c);
	}
	
	dijkstra();
	
	ll ans = INF;
	for (int i=0; i<=K; i++){
		ans = min(ans, dist[i][N]);
	}
	
	cout<<ans<<'\n';

	return 0;
}