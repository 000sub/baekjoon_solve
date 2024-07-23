#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> v;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n, m, ans = 0, temp;
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> temp;
		v.push_back(temp);
	}

	if (m > 200000) {
		cout << 0;
		return 0;
	}

	sort(v.begin(), v.end());

	int lo = 0, hi = v.size() - 1;

	while (lo < hi) {
		if (v[lo] + v[hi] == m) {
			ans++;
			lo++;
			hi--;
		}
		else if (v[lo] + v[hi] > m) hi--;
		else lo++;
	}

	cout << ans;
	return 0;
}