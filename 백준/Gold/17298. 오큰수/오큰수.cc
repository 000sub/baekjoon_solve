#include <iostream>
#include <stack>
#include <algorithm>
#include <vector>
using namespace std;

int arr[1000001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	stack<int> st;

	vector<int> v;
	int n, temp;
	

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	for (int i = n - 1; i >= 0; i--) {
		if (st.empty()) {
			v.push_back(-1);
			st.push(arr[i]);
			continue;
		}

		while (!st.empty() && st.top() <= arr[i]) st.pop();

		if (st.empty()) v.push_back(-1);
		else v.push_back(st.top());

		st.push(arr[i]);
	}

	for (int i = v.size()-1; i >=1; i--) cout << v[i] << ' ';
	cout << v[0];

	return 0;
}