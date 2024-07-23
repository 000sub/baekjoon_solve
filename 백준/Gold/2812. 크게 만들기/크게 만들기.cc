#include <iostream>
#include <algorithm>
#include <stack>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	stack<char> st;
	int n, k;
	cin >> n >> k;
	string s, ans = "";
	cin >> s;

	for (char c : s) {
		while (k>0 && !st.empty() && st.top() < c) {
			st.pop();
			k--;
		}
		st.push(c);
	}

	while (k > 0) {
		st.pop();
		k--;
	}

	while (!st.empty()) {
		ans += st.top();
		st.pop();
	}

	reverse(ans.begin(), ans.end());

	cout << ans;
	return 0;
}