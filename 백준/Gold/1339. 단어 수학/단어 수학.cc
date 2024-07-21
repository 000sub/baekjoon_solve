#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cstring>
#define PII pair<int,int>

using namespace std;
int base[26];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n;
	string a;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> a;
		for (int j = a.size() - 1, mul = 1; j>=0; j--, mul *= 10) {
			base[a[j] - 'A'] += mul;
		}
	}

	sort(base, base + 26, greater<>());

	int ans = 0;
	for (int i = 0; i < 10; i++) {
		ans += base[i] * (9 - i);
	}

	cout << ans;
	return 0;
}