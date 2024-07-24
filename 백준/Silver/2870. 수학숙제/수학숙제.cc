#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#define PII pair<int,int>

using namespace std;
typedef long long ll;

bool cmp(string& a, string& b) {
	if (a.size() != b.size()) return a.size() < b.size();

	return a < b;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n;
	string s;
	vector<string> v;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> s;

		string tmp;
		
		bool flag = false;
		for (char c : s) {
			if (isdigit(c)) {
				if (!flag) flag = true;
				tmp += c;
			}
			else {
				if (flag) {
					while (tmp[0] == '0' && tmp.size() > 1) tmp = tmp.substr(1);
					if (tmp.size() > 0) v.push_back(tmp);
					tmp = "";
					flag = false;
				}
			}
		}

		if (flag) {
			while (tmp[0] == '0' && tmp.size() > 1) tmp = tmp.substr(1);
			if (tmp.size() > 0) v.push_back(tmp);
		}
	}

	sort(v.begin(), v.end(), cmp);
	for (string i : v) cout << i << '\n';

	return 0;
}