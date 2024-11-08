#include <bits/stdc++.h>
#include <unordered_set>
#define PII pair<int,int>
using namespace std;

int N, ans = 1e9;
int arr[10001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < 2 * N; i++) cin >> arr[i];
	sort(arr, arr + 2 * N);
	int lo = 0, hi = 2 * N - 1;
	while (lo < hi) {
		ans = min(ans, arr[lo++] + arr[hi--]);
	}
	cout << ans;
	
	return 0;
}