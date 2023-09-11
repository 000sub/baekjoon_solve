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
int N, M, W;
vector<PII> graph[501];
ll dist[501];
bool is_cycle;

void update(){
	
	for (int i=1; i<=N; i++){
		for (int j=1; j<=N; j++){
			for (auto& p: graph[j]){
				if (dist[p.first] > p.second + dist[j]){
					dist[p.first] = p.second + dist[j];
					if (i==N) {
						is_cycle = true;
						return;
					}
				}
			}
			
		}
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int T;
	cin>>T;
	
	for (int tc=0; tc<T; tc++){
		cin>>N>>M>>W;
	
		int a,b,c;
		
		for (int i=0;i<M;i++){
			cin>>a>>b>>c;
			graph[a].emplace_back(b,c);
			graph[b].emplace_back(a,c);
		}
		
		for (int i=0; i<W; i++){
			cin>>a>>b>>c;
			graph[a].emplace_back(b,-c);
		}
		
		memset(dist, 0, sizeof(dist));
		is_cycle = false;
		
		update();

		if (is_cycle) cout<<"YES"<<'\n';
		else cout<<"NO"<<'\n';
		
		for (int i=1; i<=N; i++) graph[i].clear();

	}
	


	
	return 0;
}