#include <bits/stdc++.h>
#define PII pair<int,int>
#define PIII pair<int,PII>

using namespace std;
typedef long long ll;

bool cmp(PIII& a, PIII& b) {
	if (a.second.second != b.second.second) return a.second.second > b.second.second;
	return a.second.first < b.second.first;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, c, temp;
	vector<PIII> v;
	map<int, PII> m;
	cin >> n >> c;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		if (m.count(temp)) {
			m[temp].second++;
		}
		else {
			m[temp] = { i, 1 };
		}
	}
	for (auto& e : m) {
		v.push_back(PIII(e.first, e.second));
	}

	sort(v.begin(), v.end(), cmp);

	for (PIII p : v) {
		for (int i = 0; i < p.second.second; i++) cout << p.first << " ";
	}
	cout << '\n';
	return 0;
}