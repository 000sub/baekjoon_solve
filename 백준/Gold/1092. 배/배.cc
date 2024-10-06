#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>

#define PII pair<int,int>
using namespace std;

int N, M;
int C[51], cnt[51];
int B[10001];
int main() {
    cin>>N;
	for (int i=0; i<N; i++) cin>>C[i];
	cin>>M;
	for (int i=0; i<M; i++) cin>>B[i];

	sort(C, C+N, greater<>());
	sort(B, B+M, greater<>());

	for (int i=0; i<M; i++) {
		int curBox = B[i];
		int bestIdx = 0, minCnt = 1e9;
		for (int j=0; j<N; j++) {
			if (C[j] < curBox) break;
		
			if (minCnt >= cnt[j]) {
				bestIdx = j;
				minCnt = cnt[j];
			}
		}
		if (minCnt == 1e9) {
			cout<<-1;
			return 0;
		}
		cnt[bestIdx]++;
	}

	int ans = 0;

	for (int i=0; i<N; i++) {
		ans = max(ans, cnt[i]);
	}
	cout<<ans;
    return 0;
}