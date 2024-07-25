#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <string>
#define PII pair<int,int>

using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	string s;
	while (getline(cin, s)) {
		if (s == "#") return 0;

		stack<char> st;
		bool flag = true;
		for (char c : s) {
			if (c == '[' || c == '{' || c == '(') {
				st.push(c);
			}

			if (c == ']') {
				if (st.empty() || st.top() != '[') {
					flag = false;
					break;
				}
				st.pop();
			}

			else if (c == ')') {
				if (st.empty() || st.top() != '(') {
					flag = false;
					break;
				}
				st.pop();
			}

			else if (c == '}') {
				if (st.empty() || st.top() != '{') {
					flag = false;
					break;
				}
				st.pop();
			}
		}

		if (!st.empty()) flag = false;

		flag ? cout << "Legal" : cout << "Illegal";
		cout << '\n';
	}

	
	return 0;
}