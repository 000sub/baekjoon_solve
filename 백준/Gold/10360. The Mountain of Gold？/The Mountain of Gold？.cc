#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <vector>

#define MAX 1001
#define PII pair<int, int>

using namespace std;
typedef long long ll;

const ll INF = 1e15;
int N, M;
vector<PII> graph[MAX], rev_graph[MAX];
ll dist[MAX];
bool visited[MAX];
bool is_cycle;

void update(){
	is_cycle = false;
	fill(dist, dist+MAX, INF);
	dist[0] = 0;
	
	for (int i=0; i<N; i++){
		for (int j=0; j<N; j++){
			if (dist[j] == INF) continue;
			for (auto& p: graph[j]){
				if (dist[p.first] > p.second + dist[j]){
					dist[p.first] = p.second + dist[j];
					if (i==N-1 && visited[j]) {
						is_cycle = true;
						return;
					}
				}
			}
			
		}
	}
}

void check(){
	memset(visited, false, sizeof(visited));
	queue<int> q;
	
	q.push(0);
	visited[0] = true;
	while(!q.empty()){
		int tmp = q.front();
		q.pop();
		
		for (auto& p : rev_graph[tmp]){
			if (!visited[p.first]){
				q.push(p.first);
				visited[p.first] = true;
			}
		}
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int T;
	int a,b,c;
	cin>>T;
	
	for (int tc=1; tc<=T; tc++){
		cin>>N>>M;
		
		
		for (int i=0; i<M; i++){
			cin>>a>>b>>c;
			graph[a].emplace_back(b,c);
			rev_graph[b].emplace_back(a,c);
		}
		
		check();
		update();
		
		if (is_cycle) cout<<"Case #"<<tc<<": possible"<<'\n';
		else cout<<"Case #"<<tc<<": not possible"<<'\n';
		
		for (int i=0; i<MAX; i++){
			graph[i].clear();
			rev_graph[i].clear();
		}
		
	}
	
	return 0;
}