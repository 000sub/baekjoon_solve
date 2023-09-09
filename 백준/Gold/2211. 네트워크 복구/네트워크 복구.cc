#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <vector>
#include <cmath>

#define PII pair<int, int>
using namespace std;

const int INF = 1e9;
int N, M;
int dist[1002];
int pre[1002];
vector<PII> graph[1002];

void dijkstra(){
	priority_queue<PII, vector<PII>, greater<PII>> pq;
	
	for (int i=1; i<=N; i++){
		dist[i] = INF;
	}
	
	dist[1] = 0;
	pq.push(make_pair(dist[1], 1));
	
	while (!pq.empty()){
		int cost = pq.top().first;
		int idx = pq.top().second;
		pq.pop();
		
		if (dist[idx] < cost) continue;
		
		for (auto& p : graph[idx]){
			if (dist[p.first] > cost + p.second){
				dist[p.first] = cost + p.second;
				pq.push(make_pair(dist[p.first], p.first));
				pre[p.first] = idx;
			}
		}
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>N>>M;
	
	int a,b,c;
	for (int i=0; i<M; i++){
		cin>>a>>b>>c;
		graph[a].emplace_back(b,c);
		graph[b].emplace_back(a,c);
	}
	
	dijkstra();
	cout<<N-1<<'\n';
	for (int i=2; i<=N; i++){
		cout<<i<<" "<<pre[i]<<'\n';
	}

	return 0;
}