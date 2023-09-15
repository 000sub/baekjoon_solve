#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
#include <vector>

#define MAX 101
#define PII pair<int, int>

using namespace std;

int R, C;
int map[MAX][MAX], nmap[MAX][MAX];
bool visited[MAX][MAX];

int dx[9] = {1,1,1,0,0,0,-1,-1,-1};
int dy[9] = {-1,0,1,-1,0,1,-1,0,1};
vector<PII> v, nv;
const int INF = 10000;
PII I;

inline int get_dist(int x1, int y1, int x2, int y2){
	return abs(x1-x2) + abs(y1-y2);
}

PII find_next(int x, int y){
	int ans = INF;
	PII ans_pos;
	for (int i=0; i<9; i++){
		if (i==4) continue;
		int nx = x + dx[i];
		int ny = y + dy[i];
		
		if (nx<0||ny<0||nx>R-1||ny>C-1) continue;
		
		int cur = get_dist(I.first, I.second, nx, ny);
		if (ans > cur) {
			ans = cur;
			ans_pos = PII(nx, ny);
		}
	}
	
	return ans_pos;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>R>>C;
	
	string s;
	char c;
	int cnt = 0;
	
	for (int i=0; i<R; i++){
		for (int j=0; j<C; j++){
			cin>>c;
			if (c=='I') I = PII(i, j);
			else if (c=='R') {
				v.emplace_back(i, j);
				map[i][j] = 1;
			}
		}
	}
	
	cin>>s;
	
	for (int i=0; i<s.size(); i++){
		int op = s[i] - '0' - 1;
		I.first += dx[op];
		I.second += dy[op];
		cnt++;
		if (map[I.first][I.second]) {
			cout<<"kraj "<<cnt<<'\n';
			return 0;
		}
		
		
		
		for (int j = 0; j < v.size(); j++){
			PII new_pos = find_next(v[j].first, v[j].second);
			
			if (new_pos == I){
				cout<<"kraj "<<cnt<<'\n';
				return 0;
			}
						
			nmap[new_pos.first][new_pos.second]++;
			nv.push_back(new_pos);
		}
		
		v.clear();
		
		for (int j=0; j<nv.size(); j++){
			if (nmap[nv[j].first][nv[j].second] == 1) v.push_back(nv[j]);
		}
		
		memset(map, 0, sizeof(map));
		
		for (int j=0; j<R; j++){
			for (int k=0; k<C; k++){
				if (nmap[j][k] == 1) map[j][k] = 1;
			}
		}
		
		memset(nmap, 0, sizeof(nmap));
		nv.clear();
		
	}
	
	for (int i=0; i<R; i++){
		for (int j=0; j<C; j++){
			if (i == I.first && j == I.second) cout<<'I';
			else if (map[i][j]) cout<<'R';
			else cout<<'.'; 
		}
		
		cout<<'\n';
	}
	

	return 0;
}