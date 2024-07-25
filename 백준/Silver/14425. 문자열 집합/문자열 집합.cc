#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#define PII pair<int,int>

using namespace std;

set<string> SET;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n, m;
	string s;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> s;
		SET.insert(s);
	}

	int ans = 0;
	for (int i = 0; i < m; i++) {
		cin >> s;
		if (SET.count(s)) ans++;
	}

	cout << ans;
	return 0;
}