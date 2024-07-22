#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int t, k, tmp;
	cin >> t;

	for (int i = 0; i < t; i++) {
		cin >> k;
		priority_queue<ll, vector<ll>, greater<ll>> pq;

		for (int j = 0; j < k; j++) {
			cin >> tmp;
			pq.push(tmp);
		}

		ll ans = 0;

		while (pq.size() > 1) {
			ll a = pq.top();
			pq.pop();
			ll b = pq.top();
			pq.pop();

			ans += a + b;
			pq.push(a + b);
		}
		cout << ans << '\n';
	}
	return 0;
}