#include <iostream>
#include <string>
#include <queue>
#include <algorithm>
#include <tuple>

using namespace std;

int n,m;
int graph[1000][1000] = {0};
int visited[1000][1000][2] = {0};
int dy[] = {1,-1,0,0};
int dx[] = {0,0,1,-1};

int bfs(int x, int y, int pass, int cnt){
	queue<tuple<int,int,int,int>> q;
	q.push(make_tuple(x,y,pass,cnt));
	visited[y][x][pass] = 1;
	
	while (!q.empty()){
		int curx, cury, curp, curc;
		curx = get<0>(q.front());
		cury = get<1>(q.front());
		curp = get<2>(q.front());
		curc = get<3>(q.front());
		q.pop();
		
		if (curx==m-1 && cury==n-1){
			return curc;
		}
		
		for (int i=0;i<4;i++){
			int nx = curx+dx[i];
			int ny = cury+dy[i];
			
			if (nx<m && ny<n && ny>=0 && nx>=0){
				
				if (curp){
					if (!visited[ny][nx][curp] && graph[ny][nx]==0){
						visited[ny][nx][curp] = 1;
						q.push(make_tuple(nx,ny,curp,curc+1));
					}
				}
				
				else{
					if (!visited[ny][nx][curp] && graph[ny][nx]==1){
						visited[ny][nx][curp] = 1;
						q.push(make_tuple(nx,ny,curp+1,curc+1));
					}
					
					if (!visited[ny][nx][curp] && graph[ny][nx]==0){
						visited[ny][nx][curp] = 1;
						q.push(make_tuple(nx,ny,curp,curc+1));
					}
				}
			}
		}
	}
	
	return -1;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >>n>>m;
	for (int i=0;i<n;i++){
		string s;
		cin>>s;
		for (int j=0;j<m;j++){
			if (s[j]=='1'){
			
				graph[i][j]=1;
		}
		}
	}
	cout<<bfs(0,0,0,1);
	
	return 0;
}