#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#define PII pair<int,int>

using namespace std;
typedef long long ll;

int dp[15][15];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int t, k, n;

	cin >> t;

	for (int i = 1; i <= 14; i++) dp[0][i] = i;
	for (int i = 1; i <= 14; i++) {
		for (int j = 1; j <= 14; j++) {
			int sum = 0;
			for (int k = 1; k <= j; k++) sum += dp[i - 1][k];
			dp[i][j] = sum;
		}
	}
	
	while (t--) {
		cin >> k >> n;
		cout << dp[k][n]<<'\n';
	}

	return 0;
}