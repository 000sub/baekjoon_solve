#include <bits/stdc++.h>

#define PII pair<int,int>
#define PIII pair<int,PII>

using namespace std;
typedef long long ll;
char arr[7][7];
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };

int main(void) {
	//ios::sync_with_stdio(false);
	//cin.tie(0);

	int ans = 0;
	for (int i = 0; i < 7; i++) {
		for (int j = 0; j < 7; j++) {
			scanf("%c", &arr[i][j]);
		}
		getchar();
	}
	/*
	for (int i = 0; i < 2; i++) {
		for (int j = 2; j < 5; j++) {
			cin >> arr[i][j];
		}
	}
	for (int i = 2; i < 5; i++) {
		for (int j = 0; j < 7; j++) {
			cin >> arr[i][j];
		}
	}
	for (int i = 5; i < 7; i++) {
		for (int j = 2; j < 5; j++) {
			cin >> arr[i][j];
		}
	}
	*/

	for (int d = 0; d < 4; d++) {
		for (int i = 0; i < 2; i++) {
			for (int j = 2; j < 5; j++) {
				if (arr[i][j] == '.') continue;
				int nx = i + dx[d];
				int ny = j + dy[d];
				int nnx = nx + dx[d];
				int nny = ny + dy[d];
				if (nx < 0 || ny < 2 || nx>=7 || ny>4) continue;
				if (nnx < 0 || nny < 2 || nnx>=7 || nny>4) continue;
				if (arr[nx][ny] == 'o' && arr[nnx][nny] == '.') {
					ans++;
				}
			}
		}
		for (int i = 2; i < 5; i++) {
			for (int j = 0; j < 7; j++) {
				if (arr[i][j] == '.') continue;
				int nx = i + dx[d];
				int ny = j + dy[d];
				int nnx = nx + dx[d];
				int nny = ny + dy[d];

				if (j < 2) {
					if (nx < 2 || ny < 0 || nx>4 || ny>=7) continue;
					if (nnx < 2 || nny < 0 || nnx>4 || nny>= 7) continue;
				}
				else if (j < 5) {
					if (nx < 0 || ny < 0 || nx>7 || ny>=7) continue;
					if (nnx < 0 || nny < 0 || nnx>7 || nny>= 7) continue;
				}
				else {
					if (nx < 2 || ny < 0 || nx>4 || ny>=7) continue;
					if (nnx < 2 || nny < 0 || nnx>4 || nny>= 7) continue;
				}
				if (arr[nx][ny] == 'o' && arr[nnx][nny] == '.') {
					ans++;
				}
			}
		}
		for (int i = 5; i < 7; i++) {
			for (int j = 2; j < 5; j++) {
				if (arr[i][j] == '.') continue;
				int nx = i + dx[d];
				int ny = j + dy[d];
				int nnx = nx + dx[d];
				int nny = ny + dy[d];
				if (nx < 0 || ny < 2 || nx>=7 || ny>4) continue;
				if (nnx < 0 || nny < 2 || nnx>=7 || nny>4) continue;
				if (arr[nx][ny] == 'o' && arr[nnx][nny] == '.') {
					ans++;
				}
			}
		}
	}

	printf("%d", ans);
	return 0;
}