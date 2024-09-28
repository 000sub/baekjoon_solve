#include <bits/stdc++.h>

#define PII pair<int,int>
#define PIII pair<int,PII>
using namespace std;
typedef long long ll;

int N, K;
int arr[100001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> K;
	for (int i = 0; i < N; i++) cin >> arr[i];

	int lo=0, hi=K-1, sum = 0;
	for (int i = 0; i < K; i++) sum += arr[i];

	int ans = sum;

	while (hi < N-1) {
		sum -= arr[lo++];
		sum += arr[++hi];
		ans = max(ans, sum);
	}

	cout << ans;
	return 0;
}