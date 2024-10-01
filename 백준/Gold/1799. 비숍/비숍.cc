#include <bits/stdc++.h>

#define PII pair<int,int>
using namespace std;
typedef long long ll;

constexpr int dx[] = { 1,-1,-1,1 };
constexpr int dy[] = { 1,-1,1,-1 };

int N, ans = 0;
bool arr[11][11];
int visited[11][11];
vector<PII> v, v2;


bool check(int x, int y) {
	return visited[x][y] == 0;
}

void mark(int x, int y, bool flag) {
	for (int d = 0; d < 4; d++) {
		int nx = x;
		int ny = y;

		while (nx >= 0 && ny >= 0 && nx < N && ny < N) {
			flag ? visited[nx][ny]++ : visited[nx][ny]--;
			nx += dx[d];
			ny += dy[d];
		}
	}
}

void dfs(int idx, int cnt, vector<PII>& vec) {
	ans = max(ans, cnt);
	if (idx == vec.size()) return;

	if (check(vec[idx].first, vec[idx].second)) {
		mark(vec[idx].first, vec[idx].second, true);
		dfs(idx + 1, cnt + 1, vec);
		mark(vec[idx].first, vec[idx].second, false);
	}

	dfs(idx + 1, cnt, vec);
}
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
			if (arr[i][j]) {
				if ((i + j) % 2) v.push_back({ i, j });
				else v2.push_back({ i, j });
			}
		}
	}

	int total = 0;

	dfs(0, 0, v); 
	total += ans; ans = 0;
	dfs(0, 0, v2);
	total += ans;
	cout << total;
	return 0;
}