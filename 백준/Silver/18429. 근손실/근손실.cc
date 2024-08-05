#include <bits/stdc++.h>

using namespace std;

int arr[9];
bool visited[9];
int n, k, ans = 0;

void BT(int cnt, int sum) {
	if (cnt == n) {
		ans++;
		return;
	}

	for (int i = 0; i < n; i++) {
		if (!visited[i] && sum + arr[i] - k >= 500) {
			visited[i] = true;
			BT(cnt + 1, sum + arr[i] - k);
			visited[i] = false;
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	
	cin >> n >> k;
	for (int i = 0; i < n; i++) cin >> arr[i];
	BT(0, 500);

	cout << ans;
	return 0;
}