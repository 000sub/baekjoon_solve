#include <bits/stdc++.h>
#define PII pair<int,int>
using namespace std;

int N;
int arr[1001], dp[1001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) cin >> arr[i];
	for (int i = 0; i < N; i++) {
		int cnt = i + 1;
		int cost = arr[i];
		for (int j = cnt; j <= N; j ++) {
			dp[j] = max(dp[j], dp[j - cnt] + cost);
		}
	}
	cout << dp[N];
	return 0;
}