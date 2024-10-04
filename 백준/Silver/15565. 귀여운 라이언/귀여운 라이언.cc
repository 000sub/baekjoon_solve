#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <string>
#include <set>

#define PII pair<int,int>
using namespace std;

int N, K;
int arr[1000001];
const int INF = 1e9;

int main() {
    ios::sync_with_stdio(false);
	cin.tie(0);

	cin>>N>>K;
	for (int i=0; i<N; i++) cin>>arr[i];
	int lo = 0, hi = 0, ans = INF;
	int cnt = arr[lo] == 1 ? 1 : 0;
	int len = 1;
	while (lo<=hi && hi < N) {
		if (cnt >= K) {
			ans = min(ans, len);
			if (arr[lo++] == 1) cnt--;
			len--;
		}
		else {
			if (arr[++hi] == 1) cnt++;
			len++;
		}
	}

	ans == INF ? cout<<-1 : cout<<ans;
	
    return 0;
}