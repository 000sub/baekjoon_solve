#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>

#define PII pair<int,int>
using namespace std;
typedef long long ll;

int arr[5001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];

	sort(arr, arr + n);

	ll ans = 3 * 1e9 + 1;

	int loIdx, midIdx, hiIdx;

	for (int lo = 0; lo < n - 2; lo++) {
		int mid = lo + 1, hi = n - 1;
		while (mid < hi) {
			ll cur = (ll)arr[lo] + arr[mid] + arr[hi];
			if (abs(cur) < abs(ans)) {
				loIdx = lo;
				midIdx = mid;
				hiIdx = hi;
				ans = cur;
			}

			if (ans == 0) {
				cout << arr[loIdx] << ' ' << arr[midIdx] << ' ' << arr[hiIdx];
				return 0;
			}

			cur < 0 ? mid++ : hi--;
		}
		
	}

	cout << arr[loIdx] << ' ' << arr[midIdx] << ' ' << arr[hiIdx];

	return 0;
}