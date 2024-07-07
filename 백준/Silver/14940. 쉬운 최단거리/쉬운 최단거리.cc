#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
#include <cstring>
#define PII pair<int,int>
#define PIII pair<PII, int>
using namespace std;


int board[1001][1001];
int dist[1001][1001];
bool visited[1001][1001];
int n,m,t;
PII tgt;
int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};

void BFS() {
	queue<PIII> q;
	
	q.push(make_pair(tgt, 0));
	
	while (!q.empty()) {
		int cx = q.front().first.first;
		int cy = q.front().first.second;
		int curDist = q.front().second;
		q.pop();
		
		if (visited[cx][cy]) continue;
		visited[cx][cy] = true;
		dist[cx][cy] = curDist;
		
		for (int d=0; d<4; d++) {
			int nx = cx + dx[d];
			int ny = cy + dy[d];
			
			if (nx<0||ny<0||nx>n-1||ny>m-1||visited[nx][ny]||board[nx][ny] == 0) continue;
			
			q.push(make_pair(PII(nx, ny), curDist+1));
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	memset(dist, -1, sizeof(dist));
	cin>>n>>m;
	
	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			cin>>t;
			if (t==2) tgt = {i,j};
			else if (t==0) dist[i][j] = 0;
			board[i][j] = t;
		}
	}
	
	BFS();
	
	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			cout<<dist[i][j]<<' ';
		}
		cout<<'\n';
	}

}