#include <bits/stdc++.h>

#define PII pair<int,int>
#define PIII pair<int,PII>
using namespace std;
typedef long long ll;

int N, K;
int dp[1001][1001];

int run(int n, int k) {
	if (n == 1 || n == k || k==0) return 1;
	if (k == 1) return n;

	int& cur = dp[n][k];
	if (cur != -1) return cur;

	return cur = (run(n-1, k) % 10007 + run(n - 1, k-1) % 10007) % 10007;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> K;
	memset(dp, -1, sizeof(dp));

	cout << run(N, K);
	return 0;
}