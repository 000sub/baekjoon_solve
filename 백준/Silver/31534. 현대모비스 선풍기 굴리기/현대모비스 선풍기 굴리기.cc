#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>

#define PII pair<int,int>
using namespace std;
typedef long long ll;

const double PI = acos(-1);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int a, b, h;
	double ans;
	cin >> a >> b >> h;

	if (a == b) {
		cout << -1;
		return 0;
	}

	if (a > b) swap(a, b);

	if (a == 0) {
		ans = (b * b + h * h) * PI;
	}
	else {
		double topH = (double)h * a/ (b - a);
		ans = ((b * b + (h + topH) * (h + topH)) - (topH * topH + a * a)) * PI;
	}

	cout.precision(10);
	cout << ans;

	return 0;
}