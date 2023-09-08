#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <vector>

#define PII pair<int, int> 

using namespace std;
typedef long long ll;

const int INF = 1e9;
int N;
char map[101][101];
int dist[101][101];

int dx[4] = {1,0,0,-1};
int dy[4] = {0,1,-1,0};
char dirs[4] = {'S','E','W','N'};
PII s, e;

void dijkstra(){
	priority_queue<pair<pair<int, char>, PII>, vector<pair<pair<int, char>, PII>>, greater<pair<pair<int, char>, PII>>> pq;
	
	for (int i=0; i<N; i++){
		for (int j=0; j<N; j++){
			dist[i][j] = INF;
		}
	}
	
	pq.push(make_pair(make_pair(0, '*'), s));
	dist[s.first][s.second] = 0;
	while (!pq.empty()){
		int cost = pq.top().first.first;
		char dir = pq.top().first.second;
		int nx = pq.top().second.first;
		int ny = pq.top().second.second;
		pq.pop();
		
		if (dist[nx][ny] < cost) continue;
		
		for (int i=0; i<4; i++){
			int x = nx+dx[i];
			int y = ny+dy[i];
			
			if (x<0||y<0||x>N-1||y>N-1||map[x][y] == 'x') continue;

			
			if ((dir == dirs[i] || dir == '*') && dist[x][y] >= cost){
				dist[x][y] = cost;
				pq.push(make_pair(make_pair(cost, dirs[i]), PII(x,y)));
			}
			
			else if (dir != dirs[i] && dist[x][y] >= cost + 1){
				dist[x][y] = cost+1;
				pq.push(make_pair(make_pair(cost+1, dirs[i]), PII(x,y)));
			}
			
		}
	} 
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>N;
	
	for (int i=0; i<N; i++){
		for (int j=0; j<N; j++){
			cin>>map[i][j];
			
			if (map[i][j] == 'A') s = {i,j};
			else if (map[i][j] == 'B') e = {i,j};
		}
	}
	
	dijkstra();
	cout<<dist[e.first][e.second]<<'\n';

	return 0;
}