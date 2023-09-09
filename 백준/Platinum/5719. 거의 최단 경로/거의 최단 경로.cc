#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <vector>

#define PII pair<int, int>
using namespace std;

const int INF = 1e9;
int N, M, D, S;
int dist[501];
int graph[501][501];
vector<int> conn[501];
vector<int> pre[501];
void dijkstra(){
	priority_queue<PII, vector<PII>, greater<PII>> pq;
	
	for (int i=0; i<N; i++){
		dist[i] = INF;
	}
	
	dist[S] = 0;
	pq.push(make_pair(dist[S], S));
	
	while (!pq.empty()){
		int cost = pq.top().first;
		int pos = pq.top().second;
		pq.pop();
		
		if (dist[pos] < cost) continue;
		
		for (int i=0; i<conn[pos].size(); i++){
			int npos = conn[pos][i];
			int nc = graph[pos][npos];
			if (nc == -1) continue;
			
			if (dist[npos] > cost + nc){
				dist[npos] = cost + nc;
				pq.push(make_pair(dist[npos], npos));
				
				pre[npos].clear();
				pre[npos].emplace_back(pos);
			}
			
			else if (dist[npos] == cost + nc){
				pre[npos].emplace_back(pos);
			}
		}
	}
}

void remove_path(){
	queue<int> q;
	bool visited[501];
	
	memset(visited, false, sizeof(visited));
	q.push(D);
	visited[D] = true;
	while (!q.empty()){
		int pos = q.front();
		q.pop();
		auto& v = pre[pos];
		
		for (int i : v){
			graph[i][pos] = -1;
			
			if (!visited[i]){
				q.push(i);
				visited[i] = true;
			}
 
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	while (1){
		memset(graph, -1, sizeof(graph));
		cin>>N>>M;
	
		if (N==0 && M==0) break;
		
		cin>>S>>D;
		
		
		int a,b,c;
		for (int i=0; i<M; i++){
			cin>>a>>b>>c;
			graph[a][b] = c;
			conn[a].emplace_back(b);
		}
		
		dijkstra();	
		
		if (dist[D] == INF) {
			cout<<-1<<'\n';
			continue;
		}
		
		remove_path();
		dijkstra();
		
		if (dist[D] == INF) cout<<-1<<'\n';
		else cout<<dist[D]<<'\n';
		
		for (int i=0; i<501; i++){
			conn[i].clear();
			pre[i].clear();
		}
	}
	

	return 0;
}