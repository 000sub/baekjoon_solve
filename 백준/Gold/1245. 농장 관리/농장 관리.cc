#include <iostream>
#include <algorithm>
#include <queue>

#define MAX 100001
using namespace std;

int N, M;
int map[101][71];
bool visited[101][71];
queue<pair<int, int>> q;
int dx[8] = {1,1,0,-1,-1,1,0,-1};
int dy[8] = {0,1,1,1,0,-1,-1,-1};

bool bfs(int x, int y){
	bool flag = true;
	q = queue<pair<int, int>>();
	q.push(make_pair(x, y));
	visited[x][y] = true;
	
	while (!q.empty()){
		int nx = q.front().first;
		int ny = q.front().second;
		q.pop();
		visited[nx][ny] = true;
		
		for (int i=0; i<8; i++){
			int curx = nx + dx[i];
			int cury = ny + dy[i];
			
			if (curx <0 || cury <0 || curx>N-1 || cury>M-1) continue;
			if (map[x][y] < map[curx][cury]) flag = false;
			if (!visited[curx][cury] && map[curx][cury] == map[x][y]) q.push(make_pair(curx, cury));
		}
	}
	
	return flag;
}
int main(){
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>N>>M;
	
	for (int i=0; i<N; i++){
		for (int j=0; j<M; j++){
			cin>>map[i][j];
		}
	}
	
	int cnt = 0;
	for (int i=0; i<N; i++){
		for (int j=0; j<M; j++){
			if (!visited[i][j]){
				bool b = bfs(i, j);
				if (b) cnt++;
			}
		}
	}
	
	cout<<cnt<<'\n';
	

	return 0;
}