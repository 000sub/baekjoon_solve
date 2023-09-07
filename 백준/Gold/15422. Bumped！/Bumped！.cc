#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <vector>

#define PII pair<ll, int> 

using namespace std;
typedef long long ll;

const ll INF = 1LL << 60;
int N,M,F,S,T;
vector<PII> v[50001];
vector<PII> flight;
ll dist[50001];
void dijkstra(int s){
	priority_queue<PII, vector<PII>, greater<PII>> pq;
	fill(dist, dist+N, INF);
	pq.push(PII(0, s));
	
	while (!pq.empty()){
		ll curcost = pq.top().first;
		int curpos = pq.top().second;
		pq.pop();
		
		if (dist[curpos] < curcost) continue;
		
		for (auto& p : v[curpos]){
			if (dist[p.first] > curcost + p.second){
				dist[p.first] = curcost + p.second;
				pq.push(PII(dist[p.first], p.first));
			}
		}
	}
	
}
int main(){
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
		
	cin>>N>>M>>F>>S>>T;
	
	if (N==0 || S==T){
		cout<<0<<'\n';
		return 0;
	}
	ll a,b,c;
	for (int i=0; i<M; i++){
		cin>>a>>b>>c;
		v[a].emplace_back(b,c);
		v[b].emplace_back(a,c);
	}
	
	ll ans = INF;
	
	for (int i=0; i<F; i++){
		cin>>a>>b;
		v[a].emplace_back(b, 0);
		dijkstra(S);
		ans = min(ans, dist[T]);
		v[a].pop_back();
	}
	
	dijkstra(S);
	ans = min(ans, dist[T]);
	
	cout<<ans<<'\n';

	return 0;
}