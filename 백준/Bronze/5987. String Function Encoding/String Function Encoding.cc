#include <bits/stdc++.h>

#define PII pair<int,int>

using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n, c, t;
	string s, subS;
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> n >> c >> s;

		int _n = n;
		while (c--) {
			subS = s.substr(n);
			s = subS + s;
		}

		cout << s<< '\n';
	}

	
	
	return 0;
}