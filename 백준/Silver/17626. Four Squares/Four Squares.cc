#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int dp[50001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n;
	cin >> n;

	dp[1] = 1;
	for (int i = 2; i <= n; i++) {
		dp[i] = 100000;
		for (int j = 1; j*j <= i; j++) {
			dp[i] = min(dp[i], dp[i-j*j]);
		}

		dp[i]++;
	}

	cout << dp[n];

	return 0;
}