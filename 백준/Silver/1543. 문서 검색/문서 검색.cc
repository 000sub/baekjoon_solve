#include <bits/stdc++.h>

#define PII pair<int,int>
using namespace std;

string s, pat;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	getline(cin, s);
	getline(cin, pat);
	int lo = 0, hi = pat.size() - 1;
	int ans = 0;
	string cur = s.substr(0, hi+1);
	while (lo <= hi && hi < s.size()) {
		if (hi - lo == pat.size() -1) {
			if (cur == pat) {
				ans++;
				lo = hi + 1;
				hi = lo;
				cur.clear();
				cur = string(1, s[lo]);
			}
			else {
				lo++; hi++;
				cur = cur.substr(1);
				cur += s[hi];
			}
		}
		else {
			hi++;
			if (hi >= s.size()) break;
			cur += s[hi];
		}

	}
	cout << ans;
	return 0;
}