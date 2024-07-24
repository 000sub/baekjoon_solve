#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
typedef long long ll;

typedef struct pos {
	ll x;
	ll y;
	ll z;
} Pos;

Pos points[100001];
int n, m;

int check(ll x, ll y, ll z, ll r) {
	int cnt = 0;

	for (int i = 0; i < n; i++) {
		if ((x - points[i].x) * (x - points[i].x) +
			(y - points[i].y) * (y - points[i].y) +
			(z - points[i].z) * (z - points[i].z) <= r * r) cnt++;
	}

	return cnt;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	
	cin >> n;
	for (int i = 0; i < n; i++) cin >> points[i].x >> points[i].y >> points[i].z;
	cin >> m;
	
	int a, b, c, d;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c >> d;
		cout << check(a, b, c, d) << '\n';
	}
}