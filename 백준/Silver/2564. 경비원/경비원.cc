#include <bits/stdc++.h>
#define PII pair<int,int>

using namespace std;

int n, m, shopNum, ans = 0;
int shops[101];
int pos;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m >> shopNum;
	int t1, t2;

	for (int i = 0; i <= shopNum; i++) {
		cin >> t1 >> t2;

		if (t1 == 1) shops[i] = t2;
		else if (t1 == 2) shops[i] = n + m + (n - t2);
		else if (t1 == 3) shops[i] = 2 * n + m + (m - t2);
		else shops[i] = n + t2;

		if (i == shopNum) {
			pos = shops[i];
		}
	}

	int wholeDist = n * 2 + m * 2;

	for (int i = 0; i < shopNum; i++) {
		int dist = abs(shops[i] - pos);
		ans += min(dist, wholeDist - dist);
	}

	cout << ans;

	return 0;
}