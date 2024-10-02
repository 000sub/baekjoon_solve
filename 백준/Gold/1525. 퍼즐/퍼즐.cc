#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <string>
#include <set>

#define PII pair<int,int>
using namespace std;

int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};
int sx, sy; 
string initState = "";
set<string> visited;

struct QNode {
	int x;
	int y;
	int cnt;
	string state;
};

int main() {
    ios::sync_with_stdio(false);
	cin.tie(0);

	for (int i=0, k; i<3; i++) {
		for (int j=0; j<3; j++) {
			cin>>k;
			initState += to_string(k);
			if (k == 0) sx=i, sy=j;
		}
	}

	queue<QNode> q;
	visited.insert(initState);
	q.push({sx, sy, 0, initState});

	while (!q.empty()) {
		auto [x,y,cnt,state] = q.front();
		q.pop();

		if (state == "123456780") {
			cout<<cnt;
			return 0;
		}

		for (int d=0; d<4; d++) {
			int nx = x + dx[d];
			int ny = y + dy[d];
			if (nx<0||ny<0||nx>=3||ny>=3) continue;
			
			string newS = state;
			char temp = newS[x*3+y];
			newS[x*3+y] = newS[nx*3+ny];
			newS[nx*3+ny] = temp;
			if (visited.count(newS)) continue;

			visited.insert(newS);
			q.push({nx, ny, cnt+1, newS});
		}
	}
	cout<<-1;
    return 0;
}