#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
#include <cstring>
#include <cmath>
#include <map>
typedef long long ll;
using namespace std;

int board[6][6];
bool visited[6][6];
//left, up, right, down
int dx[] = {0,-1,0,1};
int dy[] = {-1,0,1,0};
int n,m;
int ans = 0;

int calc(int x, int y, int d1, int d2) {
	int cur = board[x][y];
	int d1x = x + dx[d1];
	int d1y = y + dy[d1];
	int d2x = x + dx[d2];
	int d2y = y + dy[d2];
	
	if (d1x<0||d1y<0||d1x>n-1||d1y>m-1||d2x<0||d2y<0||d2x>n-1||d2y>m-1||visited[d1x][d1y]||visited[d2x][d2y]) return 0;
	
	visited[x][y] = true;
	visited[d1x][d1y] = true;
	visited[d2x][d2y] = true;
	return cur*2 + board[d1x][d1y] + board[d2x][d2y];
	
}

void unvisit(int x, int y, int d1, int d2) {
	int d1x = x + dx[d1];
	int d1y = y + dy[d1];
	int d2x = x + dx[d2];
	int d2y = y + dy[d2];
	
	visited[x][y] = false;
	visited[d1x][d1y] = false;
	visited[d2x][d2y] = false;
}

void bt(int x, int y, int sum) {
	if (x==n) {
		ans = max(ans, sum);
		return;
	}
	if (y==m) {
		y=0; x++;
	}
	
	int temp = 0;
	
	if (!visited[x][y]) {
		temp = calc(x, y, 0, 1);
		if (temp > 0) {
			bt(x, y+1, sum+temp);
			unvisit(x, y, 0, 1);
		}
			
		temp = calc(x, y, 0, 3);
		if (temp > 0) {
			bt(x, y+1, sum+temp);
			unvisit(x, y, 0, 3);
		}
			
		temp = calc(x, y, 2, 1);
		if (temp > 0) {
			bt(x, y+1, sum+temp);
			unvisit(x, y, 2, 1);
		}
			
		temp = calc(x, y, 2, 3);
		if (temp > 0) {
			bt(x, y+1, sum+temp);
			unvisit(x, y, 2, 3);
		}
	}
	
	bt(x, y+1, sum);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin>>n>>m;
	
	for (int i=0; i<n; i++) for (int j=0; j<m; j++) cin>>board[i][j];
	bt(0,0,0);
	cout<<ans;
}