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
vector<PII> graph[MAX], rev_graph[MAX];
ll dist[MAX];
int pre[MAX];
bool visit[MAX];
bool is_cycle;

void update(){
	is_cycle = false;
	fill(dist, dist+MAX, INF);
	dist[1] = 0;
	
	for (int i=1; i<=N; i++){
		for (int j=1; j<=N; j++){
			if (dist[j] == INF) continue;
			for (auto& p: graph[j]){
				if (dist[p.first] > p.second + dist[j]){
					dist[p.first] = p.second + dist[j];
					pre[p.first] = j;
					if (i==N && visit[j]) {
						is_cycle = true;
						return;
					}
				}
			}
			
		}
	}
}

void check(){
	queue<int> q;
	q.push(N);
	while (!q.empty()){
		int tmp = q.front();
		q.pop();
		
		for (auto& p: rev_graph[tmp]){
			if (!visit[p.first]){
				q.push(p.first);
				visit[p.first] = true;
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
		graph[a].emplace_back(b,-c);
		rev_graph[b].emplace_back(a,-c);
	}
	
	check();
	
	if (!visit[1]) {
		cout<<-1<<'\n';
		return 0;
	}
	
	update();
	
	if (is_cycle) {
		cout<<-1<<'\n';
		return 0;
	}
	
	
	vector<int> ans;
	int tmp = N;
	
	while (tmp != 1){
		ans.push_back(tmp);
		tmp = pre[tmp];
	}
	ans.push_back(1);
	
	for (int i=ans.size()-1; i>=0; i--){
		cout<<ans[i]<<" ";
	}
	
	cout<<'\n';
	
	return 0;
}