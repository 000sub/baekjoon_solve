#include <bits/stdc++.h>

#define PII pair<int,int>
using namespace std;
typedef long long ll;

int N, ans = 0;
int arr[21][21], temp[21][21];
int result[6][21][21];

void copyArr(int dst[21][21], int src[21][21]) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			dst[i][j] = src[i][j];
		}
	}
}

void moveUp() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N-1; j++) {
			if (temp[j][i]) {
				int next = j + 1;
				while (next < N && temp[next][i] == 0) next++;
				if (next < N && temp[next][i] == temp[j][i]) {
					temp[j][i] *= 2;
					temp[next][i] = 0;
				}
			}
			else {
				int next = j + 1;
				while (next < N && temp[next][i] == 0) next++;
				if (next < N) {
					temp[j][i] = temp[next][i];
					temp[next][i] = 0;
					j--;
				}
			}
		}
	}
}

void moveDown() {
	for (int i = 0; i < N; i++) {
		for (int j = N-1; j>0; j--) {
			if (temp[j][i]) {
				int next = j - 1;
				while (next >= 0 && temp[next][i] == 0) next--;
				if (next >= 0 && temp[next][i] == temp[j][i]) {
					temp[j][i] *= 2;
					temp[next][i] = 0;
				}
			}
			else {
				int next = j - 1;
				while (next >= 0 && temp[next][i] == 0) next--;
				if (next >= 0) {
					temp[j][i] = temp[next][i];
					temp[next][i] = 0;
					j++;
				}
			}
		}
	}
}

void moveLeft() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N - 1; j++) {
			if (temp[i][j]) {
				int next = j + 1;
				while (next < N && temp[i][next] == 0) next++;
				if (next < N && temp[i][next] == temp[i][j]) {
					temp[i][j] *= 2;
					temp[i][next] = 0;
				}
			}
			else {
				int next = j + 1;
				while (next < N && temp[i][next] == 0) next++;
				if (next < N) {
					temp[i][j] = temp[i][next];
					temp[i][next] = 0;
					j--;
				}
			}
		}
	}
}

void moveRight() {
	for (int i = 0; i < N; i++) {
		for (int j = N-1; j > 0; j--) {
			if (temp[i][j]) {
				int next = j - 1;
				while (next >= 0 && temp[i][next] == 0) next--;
				if (next >= 0 && temp[i][next] == temp[i][j]) {
					temp[i][j] *= 2;
					temp[i][next] = 0;
				}
			}
			else {
				int next = j - 1;
				while (next >= 0 && temp[i][next] == 0) next--;
				if (next >= 0) {
					temp[i][j] = temp[i][next];
					temp[i][next] = 0;
					j++;
				}
			}
		}
	}
}

bool check(int A[21][21]) {
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (A[i][j]) {
				ans = max(ans, A[i][j]);
				cnt++;
			}
		}
	}
	return cnt == 1;
}

void dfs(int cnt) {
	if (check(result[cnt-1])) return;

	if (cnt == 6) return;


	copyArr(temp, result[cnt - 1]);
	moveUp();
	copyArr(result[cnt], temp);
	dfs(cnt + 1);
	
	copyArr(temp, result[cnt - 1]);
	moveDown();
	copyArr(result[cnt], temp);
	dfs(cnt + 1);

	copyArr(temp, result[cnt - 1]);
	moveLeft();
	copyArr(result[cnt], temp);
	dfs(cnt + 1);

	copyArr(temp, result[cnt - 1]);
	moveRight();
	copyArr(result[cnt], temp);
	dfs(cnt + 1);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) cin >> arr[i][j];
	
	if (N == 1) {
		cout << arr[0][0];
		return 0;
	}

	copyArr(result[0], arr);
	dfs(1);
	cout << ans;
	
	return 0;
}