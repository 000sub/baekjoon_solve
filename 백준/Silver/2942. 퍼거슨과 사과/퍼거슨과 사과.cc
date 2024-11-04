#include <bits/stdc++.h>
#include <unordered_set>
#define PII pair<int,int>
using namespace std;

int a, b;

int gcd(int x, int y) {
	return x % y == 0 ? y : gcd(y, x%y);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> a >> b;
	int GCD = gcd(a, b);
	for (int i = 1; i*i <= GCD; i++) {
		if (a%i==0 && b%i==0) cout << i << ' ' << a / i << ' ' << b / i << '\n';
		if (i*i != GCD) {
			int temp = GCD / i;
			if (a%temp==0 && b%temp==0) cout << temp << ' ' << a / temp << ' ' << b / temp << '\n';
		}
	}
	
	return 0;
}