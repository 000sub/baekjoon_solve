#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#define PII pair<int,int>

using namespace std;
typedef long long ll;

int DIST[100001], COST[100001];
vector<PII> v;

bool cmp(PII& a, PII& b) {
	if (a.first != b.first) return a.first < b.first;
	return a.second > b.second;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n, maxD = 0;

	cin >> n;
	for (int i = 1; i <= n - 1; i++) cin >> DIST[i];
	for (int i = 0; i < n; i++) cin >> COST[i];

	for (int i = 0; i < n; i++) {
		maxD += DIST[i];
		v.push_back({ COST[i], maxD });
	}

	ll ans = 0;
	sort(v.begin(), v.end(), cmp);

	for (PII& p : v) {
		if (maxD < p.second) continue;
		ans += (ll)(maxD - p.second) * p.first;
		maxD = p.second;
	}
	
	cout << ans;

	return 0;
}