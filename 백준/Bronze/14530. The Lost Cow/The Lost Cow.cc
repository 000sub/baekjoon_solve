#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>

#define PII pair<int,int>
using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int x, y;
	cin >> x >> y;

	int res = 0;
	bool isMinus = false;
	int pos = x;
	for (int i = 1;; i<<=1) {
		int tgt = isMinus ? x - i : x + i;
		int dist = abs(tgt - pos);
		

		if (!isMinus && pos <= y && y <= pos + dist) {
			res += y - pos;
			break;
		}
		else if (isMinus && pos - dist <= y && y <= pos) {
			res += pos - y;
			break;
		}
		else {
			res += dist;
			pos = tgt;
		}
		isMinus = !isMinus;
	}

	cout << res;

	return 0;
}