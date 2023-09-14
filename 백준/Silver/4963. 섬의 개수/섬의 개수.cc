#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <sstream>

#define MAX 51

using namespace std;

int W, H;
int map[MAX][MAX];
bool visited[MAX][MAX];

int dx[8] = {0,0,1,1,1,-1,-1,-1};
int dy[8] = {1,-1,0,-1,1,1,0,-1};

void dfs(int x, int y){
	for (int i=0; i<8; i++){
		int nx = x + dx[i];
		int ny = y + dy[i];
		
		if (nx<0 || ny<0 || nx> H-1 || ny>W-1) continue;
		
		if (map[nx][ny] == 1 && !visited[nx][ny]) {
			visited[nx][ny] = true;
			dfs(nx, ny);
		}
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	while (1) {
		cin>>W>>H;
		if (W==0 && H==0) break;
		for (int i=0;i<H; i++) for (int j=0; j<W; j++) cin>>map[i][j];
		int cnt = 0;
		for (int i=0;i<H; i++) for (int j=0; j<W; j++) if (map[i][j] == 1 && !visited[i][j]){
			cnt++;
			dfs(i, j);
		}
		cout<<cnt<<'\n';
		memset(visited, false, sizeof(visited));
	}
	
	

	return 0;
}