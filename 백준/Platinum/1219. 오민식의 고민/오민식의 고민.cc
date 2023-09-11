#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <vector>

#define MAX 51
#define PII pair<int, int>

using namespace std;
typedef long long ll;

const ll INF = 1e15;
int N, M, S, E;
vector<PII> graph[MAX], rev_graph[MAX];
ll dist[MAX];
ll P[MAX];
bool visited[MAX];
bool is_cycle;

void update(){
	is_cycle = false;
	fill(dist, dist+MAX, INF);
	dist[S] = P[S];
	
	for (int i=0; i<N; i++){
		for (int j=0; j<N; j++){
			if (dist[j] == INF) continue;
			for (auto& p: graph[j]){
				if (dist[p.first] > p.second + dist[j] + P[p.first]){
					dist[p.first] = p.second + dist[j] + P[p.first];
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
	
	q.push(E);
	visited[E] = true;
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
	
	int a,b,c;
	
	cin>>N>>S>>E>>M;
	
	
	for (int i=0; i<M; i++){
		cin>>a>>b>>c;
		graph[a].emplace_back(b,c);
		rev_graph[b].emplace_back(a,c);
	}
	
	for (int i=0; i<N; i++) {
		cin>>a;
		P[i] = -a;
	}
	
	check();
	update();
	
	if (is_cycle) cout<<"Gee"<<'\n';
	else if (dist[E] == INF) cout<<"gg"<<'\n';
	else cout<<-dist[E]<<'\n';

	
	return 0;
}