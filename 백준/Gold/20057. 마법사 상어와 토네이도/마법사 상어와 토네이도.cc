#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>

#define PII pair<int,int>

using namespace std;

int N, ans=0;
int counter = 0;
int arr[500][500];

int dx[] = {0,1,0,-1};
int dy[] = {-1,0,1,0};

void move(int nx, int ny, int total, int ratio) {
	if (nx<0||ny<0||nx>=N||ny>=N) {
		ans += total * ratio / 100;
		counter += total * ratio / 100;
	}
	else {
		arr[nx][ny] += total * ratio / 100;
		counter += total * ratio / 100;
	}
}

void moveAlpha(int nx, int ny, int val) {
	if (nx<0||ny<0||nx>=N||ny>=N) {
		ans += val;
	}
	else {
		arr[nx][ny] += val;
	}
}
void spread(int x, int y, int dir) {
	int total = arr[x][y];
	arr[x][y] = 0;
	counter = 0;

	if (dir%2 == 0) {
		move(x, y+2*dy[dir], total, 5);
		move(x-1, y+dy[dir], total, 10);
		move(x+1, y+dy[dir], total, 10);
		move(x-2, y, total, 2);
		move(x+2, y, total, 2);
		move(x-1, y, total, 7);
		move(x+1, y, total, 7);
		move(x-1, y-dy[dir], total, 1);
		move(x+1, y-dy[dir], total, 1);
		moveAlpha(x, y+dy[dir], total - counter);
	}
	else {
		move(x+2*dx[dir], y, total, 5);
		move(x+dx[dir], y-1, total, 10);
		move(x+dx[dir], y+1, total, 10);
		move(x, y-2, total, 2);
		move(x, y+2, total, 2);
		move(x, y-1, total, 7);
		move(x, y+1, total, 7);
		move(x-dx[dir], y-1, total, 1);
		move(x-dx[dir], y+1, total, 1);
		moveAlpha(x+dx[dir], y, total - counter);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
    cin>>N;
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            cin>>arr[i][j];
        }
    }

	int x = N/2;
	int y = N/2;
	int cnt = 0;
	int len = 1;
	int dir = 0;

	while (len < N) {
		for (int i=0; i<len; i++) {
			x += dx[dir];
			y += dy[dir];
			spread(x,y,dir);
		}
		dir = (dir+1)%4;
		cnt++;
		if (cnt==2) {
			cnt = 0;
			len++;
		}
	}
	for (int i=0; i<len-1; i++) {
		x += dx[dir];
		y += dy[dir];
		spread(x,y,dir);
	}

    cout<<ans;
    return 0;
}