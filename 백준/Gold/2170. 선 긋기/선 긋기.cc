#include <bits/stdc++.h>
#define PII pair<int,int>

using namespace std;

PII v[1000001];

bool cmp(PII& a, PII& b) {
	if (a.first != b.first) return a.first < b.first;
	return a.second > b.second;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int n;
	int x, y;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		v[i].first = x;
		v[i].second = y;
	}

	sort(v, v + n, cmp);

	int ans = 0;
	x = -1e9, y = -1e9;
	for (int i = 0; i < n; i++) {
		if (y < v[i].first) {
			ans += y - x;
			y = v[i].second;
			x = v[i].first;
		}
		else {
			y = max(y, v[i].second);
		}
	}
	ans += y - x;

	cout << ans;
	return 0;
}