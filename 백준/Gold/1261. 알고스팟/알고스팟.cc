#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <vector>

#define PII pair<int, int> 

using namespace std;
typedef long long ll;

const int INF = 1e9;
int N,M;
char map[101][101];
int dist[101][101];

int dx[4] = {1,0,0,-1};
int dy[4] = {0,1,-1,0};

void dijkstra(){
	priority_queue<pair<int, PII>, vector<pair<int, PII>>, greater<pair<int, PII>>> pq;
	
	for (int i=0; i<N; i++){
		for (int j=0; j<M; j++){
			dist[i][j] = INF;
		}
	}
	
	pq.push(make_pair(0, PII(0, 0)));
	dist[0][0] = 0;
	while (!pq.empty()){
		int cost = pq.top().first;
		int nx = pq.top().second.first;
		int ny = pq.top().second.second;
		pq.pop();
		
		if (dist[nx][ny] < cost) continue;
		
		for (int i=0; i<4; i++){
			int x = nx+dx[i];
			int y = ny+dy[i];
			
			if (x<0||y<0||x>N-1||y>M-1) continue;
			
			if (map[x][y] == '0' && dist[x][y] > cost){
				dist[x][y] = cost;
				pq.push(make_pair(cost, PII(x,y)));
			}
			
			else if (map[x][y] == '1' && dist[x][y] > cost + 1){
				dist[x][y] = cost+1;
				pq.push(make_pair(cost+1, PII(x,y)));
			}
			
		}
	} 
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
		
	cin>>M>>N;
	
	for (int i=0; i<N; i++){
		for (int j=0; j<M; j++){
			cin>>map[i][j];
		}
	}
	
	dijkstra();
	cout<<dist[N-1][M-1]<<'\n';

	return 0;
}