#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#define PII pair<int,int>

using namespace std;
typedef long long ll;

ll n, a;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n >> a;
	
	ll minA = a, maxA = a;
	for (int i = n - 1; i >= 0; i--) {
		if (minA & (1LL << i)) {
			minA ^= (1LL << i);
			break;
		}
	}

	for (int i = n - 1; i >= 0; i--) {
		if ((maxA & (1LL << i)) == 0) {
			maxA |= (1LL << i);
			break;
		}
	}
	cout << minA << ' ' << maxA;

	return 0;
}