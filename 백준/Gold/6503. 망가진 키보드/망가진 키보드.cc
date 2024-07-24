#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>

using namespace std;
typedef long long ll;

int counter[128];

int getCharCnt() {
	int res = 0;
	for (int i = 0; i < 128; i++) {
		if (counter[i] > 0) res++;
	}
	return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n;
	string s;

	while (1) {
		cin >> n;
		if (n == 0) return 0;

		cin.ignore();
		getline(cin, s);

		memset(counter, 0, sizeof(counter));
		int lo = 0, hi = 0, ans = 0;
		counter[s[lo]]++;
		while (lo <= hi) {
			int cnt = getCharCnt();
			if (cnt <= n) {
				ans = max(ans, hi - lo + 1);
				hi++;
				if (hi == s.size()) break;
				counter[s[hi]]++;
			}
			else {
				counter[s[lo]]--;
				lo++;
			}
		}

		cout << ans << '\n';
	}
	
}