#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <string>
#define PII pair<int,int>

using namespace std;
typedef long long ll;

vector<unsigned> v;
int n, k, ans = 0;

unsigned hashStr(string s) {
	unsigned res = 0;

	for (char c : s) {
		res |= (1 << (c - 'a'));
	}

	return res;
}

void check(unsigned curState) {
	int cnt = 0;
	for (unsigned u : v) {
		if ((u & curState) == u) cnt++;
	}
	ans = max(ans, cnt);
}

void BT(int cnt, int idx, unsigned state) {
	if (cnt == k) {
		check(state);
		return;
	}

	for (int i = idx+1; i < 26; i++) {
		if ((state & (1 << i)) == 0) {
			state |= (1 << i);
			BT(cnt+1, i, state);
			state ^= (1 << i);
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		v.push_back(hashStr(s));
	}

	if (k < 5) {
		cout << 0;
		return 0;
	}

	unsigned initState = 0;
	initState |= (1 << ('a' - 'a'));
	initState |= (1 << ('n' - 'a'));
	initState |= (1 << ('t' - 'a'));
	initState |= (1 << ('i' - 'a'));
	initState |= (1 << ('c' - 'a'));

	BT(5, 0, initState);

	cout << ans;

	return 0;
}