#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cstring>
#define PII pair<int,int>

using namespace std;
typedef long long ll;
typedef long double ld;

ll n, l, w, h;

int main() {
	//ios::sync_with_stdio(false);
	//cin.tie(0); cout.tie(0);

	cin >> n >> l >> w >> h;

	ld lo = 0, hi = max(l, max(w,h));
	ld mid;

	for (int i = 0; i < 10000; i++) {
		mid = (lo + hi) / 2;
		if ((ll)(l / mid) * (ll)(w / mid) * (ll)(h / mid) >= n) lo = mid;
		else hi = mid;
	}

	printf("%.10Lf", lo);


	return 0;
}
