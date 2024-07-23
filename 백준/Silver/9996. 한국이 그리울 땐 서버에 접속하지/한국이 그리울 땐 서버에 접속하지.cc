#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	int n;
	string s, first, last;

	cin >> n;
	cin >> s;
	int starIdx;
	for (int j = 0; j < s.size(); j++) {
		if (s[j] == '*') {
			starIdx = j;
			break;
		}
	}

	first = s.substr(0, starIdx);
	last = s.substr(starIdx+1);

	for (int i = 0; i < n; i++) {
		bool flag = true;
		string cur;
		cin >> cur;

		if (first.size() + last.size() > cur.size()) flag = false;

		for (int j = 0; j < first.size(); j++) {
			if (first[j] != cur[j]) flag = false;
		}
		for (int j = 0; j < last.size(); j++) {
			int curIdx = cur.size() - last.size() + j;
			if (last[j] != cur[curIdx]) flag = false;
		}

		flag ? cout << "DA" : cout << "NE";
		cout << '\n';
	}

	return 0;
}