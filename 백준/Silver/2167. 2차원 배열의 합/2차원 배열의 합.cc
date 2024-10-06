#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>

#define PII pair<int,int>
using namespace std;

int N, M, K;
int arr[301][301], pSum[301][301];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin>>N>>M;
	for (int i=1; i<=N; i++) for (int j=1; j<=M; j++) cin>>arr[i][j];
	for (int i=1; i<=N; i++) {
		pSum[i][1] = pSum[i-1][1] + arr[i][1];
		for (int j=1; j<=M; j++) {
			pSum[i][j] = pSum[i][j-1] + pSum[i-1][j] - pSum[i-1][j-1] + arr[i][j];
		}
	}

    cin>>K;
	int sx,sy,ex,ey;
	for (int i=0; i<K; i++) {
		cin>>sx>>sy>>ex>>ey;
		cout<<pSum[ex][ey] - pSum[ex][sy-1] - pSum[sx-1][ey] + pSum[sx-1][sy-1] <<'\n';
	}
    return 0;
}