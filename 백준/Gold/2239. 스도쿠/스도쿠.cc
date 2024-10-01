#include <bits/stdc++.h>

#define PII pair<int,int>
using namespace std;
typedef long long ll;

int arr[9][9];

bool check(int x, int y, int num) {
	bool visited[10] = { false, };

	for (int i = 0; i < 9; i++) {
		if (arr[x][i] == num || arr[i][y] == num) return false;
	}

	int sx = (x / 3) * 3;
	int sy = (y / 3) * 3;

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (arr[sx + i][sy + j] == num) return false;
		}
	}

	return true;
}

void dfs(int idx) {
	if (idx == 81) {
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				cout << arr[i][j];
			}
			cout << '\n';
		}
		exit(0);
	}

	if (arr[idx / 9][idx % 9] > 0) {
		dfs(idx + 1);
		return;
	}

	for (int i = 1; i <= 9; i++) {
		if (check(idx / 9, idx % 9, i)) {
			arr[idx / 9][idx % 9] = i;
			dfs(idx + 1);
			arr[idx / 9][idx % 9] = 0;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	char ch;

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> ch;
			arr[i][j] = ch - '0';
		}
	}

	dfs(0);
	return 0;
}