#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <vector>

#define MAX 101

using namespace std;

struct info{
	int pos;
	int cost;
	int dist;
};

struct cmp {
	bool operator()(struct info& a, struct info& b){
		if (a.dist == b.dist) return a.cost > b.cost;
		return a.dist > b.dist;
	}
};

bool cmp2(struct info& a, struct info& b){
	if (a.dist == b.dist) return a.cost < b.cost;
	return a.dist < b.dist;
}

const int INF = 1e9;
int T, N, M, K;
int dist[MAX][10001];
vector<info> graph[MAX];


void dijkstra(){
	priority_queue<info, vector<info>, cmp> pq;
	
	for (int i=0; i<=N; i++){
		for (int j=0; j<=M; j++){
			dist[i][j] = INF;
		}
	}
	
	dist[1][M] = 0;
	pq.push({1, M, dist[1][M]});
	
	while (!pq.empty()){
		int nc = pq.top().cost;
		int np = pq.top().pos;
		int nd = pq.top().dist;
		pq.pop();
		
		if (dist[np][nc] < nd) continue;
		
		for (auto& i : graph[np]){
			if (nc - i.cost >= 0 &&  dist[i.pos][nc - i.cost] > nd + i.dist){
				for (int j=nc-i.cost; j>=0; j--){
					if (dist[i.pos][j] <= nd + i.dist) break;
					dist[i.pos][j] = nd + i.dist;
				}
				
				pq.push({i.pos, nc - i.cost, dist[i.pos][nc - i.cost]});
			}

		}
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>T;
	
	for (int tc=0; tc<T; tc++){
		cin>>N>>M>>K;
		
		int a,b,c,d;
		for (int i=0; i<K; i++){
			cin>>a>>b>>c>>d;
			graph[a].push_back({b,c,d});
		}
		
		for (int i=1; i<=N; i++) sort(graph[i].begin(), graph[i].end(), cmp2);
		
		int ans = INF;
		dijkstra();
		
		for (int i=0; i<=M; i++) ans = min(ans, dist[N][i]);
		
		if (ans==INF) cout<<"Poor KCM"<<'\n';
		else cout<<ans<<'\n';
		
		for (int i=0; i<=N; i++) graph[i].clear();
		
	}

	
	return 0;
}