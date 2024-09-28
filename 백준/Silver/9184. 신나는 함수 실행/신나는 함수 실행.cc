#include <bits/stdc++.h>

#define PII pair<int,int>
#define PIII pair<int,PII>
using namespace std;
typedef long long ll;

int x, y, z;
int dp[21][21][21];

int w(int a, int b, int c) {
	if (a <= 0 || b <= 0 || c <= 0) return 1;
	if (a > 20 || b > 20 || c > 20) return w(20, 20, 20);

	int& cur = dp[a][b][c];
	if (cur != -1) return cur;

	if (a < b && b < c) return cur = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
	return cur = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
}
int main() {
	/*ios::sync_with_stdio(false);
	cin.tie(0);*/
	memset(dp, -1, sizeof(dp));

	while (true) {
		cin >> x >> y >> z;
		if (x == -1 && y == -1 && z == -1) break;
		printf("w(%d, %d, %d) = %d\n", x, y, z, w(x, y, z));
	}
	

	return 0;
}