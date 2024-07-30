#include <bits/stdc++.h>

#define PII pair<int,int>
using namespace std;
typedef long long ll;

int A[1001], B[1001];
vector<int> aSum, bSum;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int t, n, m, sum;
	cin >> t >> n;
	for (int i = 0; i < n; i++) {
		cin >> A[i];
		sum = A[i];
		aSum.push_back(sum);
		for (int j = i-1; j >= 0; j--) {
			sum += A[j];
			aSum.push_back(sum);
		}
	}
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> B[i];
		sum = B[i];
		bSum.push_back(sum);
		for (int j = i - 1; j >= 0; j--) {
			sum += B[j];
			bSum.push_back(sum);
		}
	}

	sort(bSum.begin(), bSum.end());

	ll ans = 0;

	for (int i = 0; i < aSum.size(); i++) {
		ans += upper_bound(bSum.begin(), bSum.end(), t - aSum[i]) - lower_bound(bSum.begin(), bSum.end(), t - aSum[i]);
	}

	cout << ans;
	
	return 0;
}