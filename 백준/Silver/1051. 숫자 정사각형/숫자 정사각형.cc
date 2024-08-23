#include <bits/stdc++.h>

#define PII pair<int,int>
#define PIII pair<int,PII>

using namespace std;
typedef long long ll;

int n, m;
char arr[51][51];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;
	int ans = 1;
	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) cin >> arr[i][j];

	int len = min(n, m);
	for (int d = 2; d <= len; d++) {
		for (int i = 0; i <= n - d; i++) {
			for (int j = 0; j <= m - d; j++) {
				if (arr[i][j] == arr[i + d - 1][j] && arr[i + d - 1][j] == arr[i][j + d - 1] && arr[i][j + d - 1] == arr[i + d - 1][j + d - 1])
					ans = max(ans, d * d);
			}
		}
	}
	cout << ans;
	return 0;
}