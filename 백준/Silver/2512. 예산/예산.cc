#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define PII pair<int,int>

using namespace std;
typedef long long ll;

int n, b;
int arr[10001];

int check(int k) {
	int res = 0;
	for (int i = 0; i < n; i++) {
		res += min(arr[i], k);
	}
	return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];
	cin >> b;


	int maxN = 0;
	for (int i = 0; i < n; i++) {
		maxN = max(maxN, arr[i]);
	}

	int lo = 1, hi = maxN;


	while (lo <= hi) {
		int mid = (lo + hi) / 2;
		int cur = check(mid);

		if (cur > b) {
			hi = mid - 1;
		}
		else if (cur < b) {
			lo = mid + 1;
		}
		else lo++;
	}

	

	cout << lo - 1;

	return 0;
}