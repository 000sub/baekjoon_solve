#include <iostream>
#include <algorithm>
#include <string>
#include <stack>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	string s;

	while (getline(cin, s)) {
		stack<char> st;
		if (s == ".") break;
		bool flag = true;

		for (char c : s) {
			if (c == '(' || c == '[') st.push(c);
			if (c == ')') {
				if (st.empty() || st.top() != '(') {
					flag = false;
					break;
				}
				else st.pop();
			}
			if (c == ']') {
				if (st.empty() || st.top() != '[') {
					flag = false;
					break;
				}
				else st.pop();
			}
		}
		if (!st.empty()) flag = false;

		flag ? cout << "yes" : cout << "no";
		cout << '\n';
	}

	return 0;
}