#include <bits/stdc++.h>

#define PII pair<int,int>
#define PIII pair<int,PII>

using namespace std;
typedef long long ll;

int N, M, D, ans = 0;
int arr[16][16];
bool visited[16][16];
vector<int> v;
set<PII> temp;

int getDist(int x1, int y1, int x2, int y2) {
	return abs(x1 - x2) + abs(y1 - y2);
}

PII findEnemy(int arcX, int arcY) {
	int minDist = 1e9;
	int minX = -1;
	int minY = -1;
	for (int j = M - 1; j >= 0; j--) {
		for (int i = arcX - 1; i >= 0; i--) {
			int curDist = getDist(i, j, arcX, arcY);
			if (arr[i][j] && !visited[i][j] && curDist <= D) {
				if (minDist >= curDist) {
					minX = i;
					minY = j;
					minDist = curDist;
				}
			}
		}
	}

	return {minX, minY};
}

void simulate() {
	int cnt = 0;
	memset(visited, false, sizeof(visited));

	for (int i = N; i > 0; i--) {
		temp.clear();
		for (int arcY : v) {
			PII p = findEnemy(i, arcY);
			if (p.first != -1) temp.insert(p);
		}
		for (PII p : temp) visited[p.first][p.second] = true;
		cnt += temp.size();
	}

	ans = max(ans, cnt);
}

void bt(int idx, int cnt) {
	if (cnt == 3) {
		simulate();
		return;
	}

	for (int i = idx; i < M; i++) {
		v.push_back(i);
		bt(i + 1, cnt + 1);
		v.pop_back();
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N>>M>>D;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
		}
	}

	bt(0, 0);
	cout << ans;
	return 0;
}