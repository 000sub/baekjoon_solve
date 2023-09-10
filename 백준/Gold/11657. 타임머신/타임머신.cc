#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <vector>

#define MAX 101
#define PII pair<int, int>
using namespace std;
typedef long long ll;

const ll INF = 1e15;
int N, M;
vector<PII> graph[501];
ll dist[501];
bool is_cycle;

void update(){
	fill(dist, dist+N+1, INF);
	
	dist[1] = 0;
	is_cycle = false;
	
	for (int i=1; i<=N; i++){
		for (int j=1; j<=N; j++){
			if (dist[j] == INF) continue;
			for (auto& p: graph[j]){
				if (dist[p.first] > p.second + dist[j]){
					dist[p.first] = p.second + dist[j];
					if (i==N) is_cycle = true;
				}
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
	
	for (int i=0;i<M;i++){
		cin>>a>>b>>c;
		graph[a].emplace_back(b,c);
	}
	
	update();
	
	if (is_cycle) cout<<-1<<'\n';
	else {
		for (int i=2; i<=N; i++){
			if (dist[i] == INF) cout<<-1<<'\n';
			else cout<<dist[i]<<'\n';
		}
	}


	
	return 0;
}