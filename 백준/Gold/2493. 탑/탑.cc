#include <iostream>
#include <stack>
#include <algorithm>
#include <vector>
#define PII pair<int,int>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	stack<PII> st;

	vector<int> v;
	int n, temp;

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> temp;

		if (st.empty()) {
			v.push_back(0);
			st.push({ temp, i });
			continue;
		}
		
		while (!st.empty() && st.top().first <= temp) st.pop();

		if (st.empty()) v.push_back(0);
		else v.push_back(st.top().second);
		st.push({ temp, i });
	}

	for (int i = 0; i < v.size() - 1; i++) cout << v[i] << ' ';
	cout << v[v.size()-1];

	return 0;
}