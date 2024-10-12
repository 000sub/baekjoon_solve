#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
#include <set>
#include <string>
#include <map>

#define PII pair<int,int>
using namespace std;

int dx[] = {0,-1,-1,-1,0,1,1,1};
int dy[] = {-1,-1,0,1,1,1,0,-1};

int ddx[] = {-1,-1,1,1};
int ddy[] = {-1,1,-1,1};

const int INF = 1e9;

int N, M;
int arr[51][51], temp[51][51];
bool exist[51][51], mark[51][51];

void init() {
	cin>>N>>M;
	for (int i=0; i<N; i++) {
		for (int j=0; j<N; j++) {
			cin>>arr[i][j];
		}
	}

	for (int i=N-1; i>=N-2; i--) {
		for (int j=0; j<2; j++) {
			exist[i][j] = true;
		}
	}
}

void move(int dir, int len) {
	memset(mark, false, sizeof(mark));
	for (int i=0; i<N; i++) {
		for (int j=0; j<N; j++) {
			if (exist[i][j]) {
				int nx = i;
				int ny = j;
				for (int k=0; k<len; k++) {
					nx += dx[dir];
					ny += dy[dir];
					if (nx<0) nx = N-1;
					if (ny<0) ny = N-1;
					if (nx>=N) nx = 0;
					if (ny>=N) ny = 0;
				}
				arr[nx][ny]++;
				mark[nx][ny] = true;
			}
		}
	}
}

void magic() {
	memset(temp, 0, sizeof(temp));

	for (int i=0; i<N; i++) {
		for (int j=0; j<N; j++) {
			if (mark[i][j]) {
				int cnt = 0;
				for (int d=0; d<4; d++) {
					int nx = i + ddx[d];
					int ny = j + ddy[d];
					if (nx>=0 && ny>=0 && nx<N && ny<N && arr[nx][ny]>0) cnt++; 
				}
				temp[i][j] = cnt;
			}
		}
	}

	for (int i=0; i<N; i++) {
		for (int j=0; j<N; j++) {
			arr[i][j] += temp[i][j];
		}
	}
}

void putNewCloud() {
	memset(exist, false, sizeof(exist));
	for (int i=0; i<N; i++) {
		for (int j=0; j<N; j++) {
			if (!mark[i][j] && arr[i][j] >= 2) {
				exist[i][j] = true;
				arr[i][j] -= 2;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
    init();
	for (int i=0,d,s; i<M; i++) {
		cin>>d>>s;
		move(d-1, s);
		magic();
		putNewCloud();
	}

	int ans = 0;
	for (int i=0; i<N; i++) {
		for (int j=0; j<N; j++) {
			ans += arr[i][j];
		}
	}
	cout<<ans;
    return 0;
}