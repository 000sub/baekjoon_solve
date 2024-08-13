#include <bits/stdc++.h>
#define PII pair<int,int>

using namespace std;
int n;
int ans = 1e9;
int a[11], b[11];

void BT(int idx, int cnt, int mul, int sum) {
	if (idx == n && cnt > 0) {
		ans = min(ans, abs(mul - sum));
		return;
	}

	for (int i = idx; i < n; i++) {
		BT(i + 1, cnt+1, mul*a[i], sum + b[i]);
		BT(i + 1, cnt, mul, sum);
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i] >> b[i];
	}

	BT(0, 0, 1, 0);

	cout << ans;

	
	return 0;
}