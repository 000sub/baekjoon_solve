#include <bits/stdc++.h>
using namespace std;

int N;
int arr[100001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) cin >> arr[i];

	if (N == 1) {
		cout << arr[0];
		return 0;
	}

	sort(arr, arr + N);
	
	int ans = 0;
	int lo = 0, hi = N - 1;
	while (lo < hi) {
		ans += arr[hi] * 2;
		lo++;
		hi--;
	}

	if (lo == hi) ans += arr[lo];
	cout << ans;
	return 0;
}