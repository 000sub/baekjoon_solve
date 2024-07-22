#include <iostream>
#include <algorithm>
#include <queue>

#define PII pair<int,int>
using namespace std;

int H[3];
int dp[61][61][61];
int dam[] = { 1,3,9 };
const int INF = 1e9;

int solve(int a, int b, int c) {
	int localDam[3] = { 1,3,9 };

	if (dp[a][b][c] != INF) return dp[a][b][c];
	do {
		int _a = a - localDam[0] < 0 ? 0 : a - localDam[0];
		int _b = b - localDam[1] < 0 ? 0 : b - localDam[1];
		int _c = c - localDam[2] < 0 ? 0 : c - localDam[2];
		dp[a][b][c] = min(dp[a][b][c], solve(_a,_b,_c)+1);
	} while (next_permutation(localDam, localDam + 3));

	return dp[a][b][c];
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	for (int i = 0; i < 61; i++)
		for (int j = 0; j < 61; j++)
			for (int k = 0; k < 61; k++)
				dp[i][j][k] = INF;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> H[i];
	
	do {
		for (int i = 0; i <= dam[0]; i++)
			for (int j = 0; j <= dam[1]; j++)
				for (int k = 0; k <= dam[2]; k++)
					dp[i][j][k] = 1;
	} while (next_permutation(dam, dam + 3));

	cout << solve(H[0], H[1], H[2]);

	return 0;
}