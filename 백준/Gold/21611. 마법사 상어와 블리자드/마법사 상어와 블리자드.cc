#include <bits/stdc++.h>

#define PII pair<int,int>
using namespace std;
typedef long long ll;

int N, M;
int arr[50][50];
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
int result[4];
queue<int> q;

void destroy(int dir, int len) {
	int x = N / 2;
	int y = N / 2;

	for (int i = 1; i <= len; i++) {
		x += dx[dir];
		y += dy[dir];
		arr[x][y] = 0;
	}
}

void putMarvels() {
	int x = N / 2;
	int y = N / 2;

	int len = 1;
	int dir = 2;
	int cnt = 0;

	while (len <= N) {
		for (int i = 0; i < len; i++) {
			x += dx[dir];
			y += dy[dir];
			if (x < 0 || y < 0 || x >= N || y >= N) break;
			if (arr[x][y] > 0) q.push(arr[x][y]);
		}
		cnt++;
		switch (dir) {
		case 0:
			dir = 2;
			break;
		case 1:
			dir = 3;
			break;
		case 2:
			dir = 1;
			break;
		case 3:
			dir = 0;
			break;
		}
		if (cnt == 2) {
			cnt = 0;
			len++;
		}
	}
}

void rearrange() {
	int x = N / 2;
	int y = N / 2;

	int len = 1;
	int dir = 2;
	int cnt = 0;

	while (len <= N) {
		for (int i = 0; i < len; i++) {
			x += dx[dir];
			y += dy[dir];
			if (x < 0 || y < 0 || x >= N || y >= N) break;
			if (!q.empty()) {
				arr[x][y] = q.front();
				q.pop();
			}
			else {
				arr[x][y] = 0;
			}
		}
		cnt++;
		switch (dir) {
		case 0:
			dir = 2;
			break;
		case 1:
			dir = 3;
			break;
		case 2:
			dir = 1;
			break;
		case 3:
			dir = 0;
			break;
		}
		if (cnt == 2) {
			cnt = 0;
			len++;
		}
	}
	while (!q.empty()) q.pop();
}

bool popMarvels() {
	int x = N / 2;
	int y = N / 2;
	bool popped = false;

	int len = 1;
	int dir = 2;
	int cnt = 0;
	int mNo = -1;
	queue<PII> posQ;

	while (len <= N) {
		for (int i = 0; i < len; i++) {
			x += dx[dir];
			y += dy[dir];
			if (x < 0 || y < 0 || x >= N || y >= N) break;
			if (arr[x][y] == 0) continue;


			if (arr[x][y] != mNo) {
				if (posQ.size() >= 4) {
					popped = true;
					result[mNo] += posQ.size();
					while (!posQ.empty()) {
						auto[cx, cy] = posQ.front();
						posQ.pop();
						arr[cx][cy] = 0;
					}
				}
				else {
					while (!posQ.empty()) posQ.pop();
				}
				mNo = arr[x][y];
			}
			posQ.push({ x,y });

		}
		cnt++;
		switch (dir) {
		case 0:
			dir = 2;
			break;
		case 1:
			dir = 3;
			break;
		case 2:
			dir = 1;
			break;
		case 3:
			dir = 0;
			break;
		}
		if (cnt == 2) {
			cnt = 0;
			len++;
		}
	}
	if (posQ.size() >= 4) {
		popped = true;
		result[mNo] += posQ.size();
		while (!posQ.empty()) {
			auto[cx, cy] = posQ.front();
			posQ.pop();
			arr[cx][cy] = 0;
		}
	}
	return popped;
}

void convert() {
	int x = N / 2;
	int y = N / 2;

	int len = 1;
	int dir = 2;
	int cnt = 0;
	int mNo = -1;
	int mSize = 0;

	while (len <= N) {
		for (int i = 0; i < len; i++) {
			x += dx[dir];
			y += dy[dir];
			if (x < 0 || y < 0 || x >= N || y >= N) break;
			if (arr[x][y] == 0) continue;

			if (arr[x][y] != mNo) {
				if (mSize > 0) {
					q.push(mSize);
					q.push(mNo);
					mSize = 0;
				}
				mNo = arr[x][y];
			}
			mSize++;
		}
		cnt++;
		switch (dir) {
		case 0:
			dir = 2;
			break;
		case 1:
			dir = 3;
			break;
		case 2:
			dir = 1;
			break;
		case 3:
			dir = 0;
			break;
		}
		if (cnt == 2) {
			cnt = 0;
			len++;
		}
	}
	if (mSize > 0) {
		q.push(mSize);
		q.push(mNo);
		mSize = 0;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) cin >> arr[i][j];
	for (int i = 0, d, s; i < M; i++) {
		cin >> d >> s;
		destroy(d - 1, s);
		do {
			putMarvels();
			rearrange();
		} while (popMarvels());
		convert();
		rearrange();

	}

	cout << result[1] + 2 * result[2] + 3 * result[3];
	return 0;
}