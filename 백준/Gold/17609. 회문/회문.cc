#include <bits/stdc++.h>
#define PII pair<int,int>
using namespace std;

int T;
string s;

int check(int left, int right, bool tried) {
	while (left < right) {
		if (s[left] != s[right]) {
			if (!tried) {
				if (check(left + 1, right, true) == 0 || check(left, right - 1, true) == 0) {
					return 1;
				}
			}
			return 2;
		}
		left++;
		right--;
	}

	return 0;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> T;
	while (T--) {
		cin >> s;
		cout << check(0, s.size() - 1, false) << '\n';
	}
	return 0;
}