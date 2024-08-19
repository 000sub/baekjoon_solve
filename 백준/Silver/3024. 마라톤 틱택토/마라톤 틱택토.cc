#include <bits/stdc++.h>

#define PII pair<int,int>
#define PIII pair<int,PII>

using namespace std;

int N;
char arr[31][31];
bool visited[31][31];
int dx[] = { 1,1,1,0,0,-1,-1,-1 };
int dy[] = { 1,0,-1,1,-1,1,0,-1 };

void search(int x, int y) {
	char tgt = arr[x][y];

	for (int d = 0; d < 8; d++) {
		int len = 1;
		int nx = x + dx[d];
		int ny = y + dy[d];

		while (nx >= 0 && ny >= 0 && nx < N && ny < N && arr[nx][ny] == tgt) {
			len++;
			nx += dx[d];
			ny += dy[d];
		}

		if (len >= 3) {
			cout << tgt;
			exit(0);
		}
	}
}

int main(void) {
	ios::sync_with_stdio(false);

	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> arr[i][j];

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!visited[i][j] && arr[i][j] != '.') search(i, j);
		}
	}

	cout << "ongoing";
	return 0;
}