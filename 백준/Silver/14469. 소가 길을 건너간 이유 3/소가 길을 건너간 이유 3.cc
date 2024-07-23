#include <iostream>
#include <algorithm>
#include <queue>
#define PII pair<int,int>
using namespace std;
typedef long long ll;

PII cows[101];

bool cmp(PII& a, PII& b) {
	if (a.first != b.first) return a.first < b.first;
	return a.second > b.second;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) cin >> cows[i].first >> cows[i].second;
	sort(cows, cows + n, cmp);

	int ans = 0;
	for (PII& cow : cows) {
		if (ans < cow.first) {
			ans = cow.first;
		}
		ans += cow.second;
	}

	cout << ans;
	return 0;
}