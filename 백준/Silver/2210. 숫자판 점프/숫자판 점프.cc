#include <bits/stdc++.h>

#define PII pair<int,int>
using namespace std;
typedef long long ll;

char arr[5][5];
int dx[] = { 0,1,0,-1 };
int dy[] = { 1,0,-1,0 };
set<string> SET;

void dfs(int x, int y, int cnt, string cur) {
	if (cnt == 6) {
		SET.insert(cur);
		return;
	}

	for (int d = 0; d < 4; d++) {
		int nx = x + dx[d];
		int ny = y + dy[d];
		if (nx < 0 || ny < 0 || nx >= 5 || ny >= 5) continue;
		dfs(nx, ny, cnt + 1, cur + arr[nx][ny]);
	}


}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	for (int i = 0; i < 5; i++) for (int j = 0; j < 5; j++) cin >> arr[i][j];
	for (int i = 0; i < 5; i++) for (int j = 0; j < 5; j++) dfs(i, j, 1, string(1, arr[i][j]));

	cout << SET.size();
	return 0;
}