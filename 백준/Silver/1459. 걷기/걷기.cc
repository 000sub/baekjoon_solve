#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#define PII pair<int,int>

using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	ll x, y, w, s;

	cin >> x >> y >> w >> s;
	if (x < y) swap(x, y);

	if (w * 2 < s) {
		cout << (x + y)*w;
	}
	else {
		if (w > s) {
			if ((x - y) % 2) cout << (x - 1) * s + w;
			else cout << x * s;
		}
		else cout << y * s + (x - y)*w;
	}
	return 0;
}