#include <bits/stdc++.h>
#define PII pair<int,int>
#define PIII pair<int,PII>

using namespace std;
typedef long long ll;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m, temp;
	vector<int> A, B;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		A.push_back(temp);
	}
	for (int i = 0; i < m; i++) {
		cin >> temp;
		B.push_back(temp);
	}

	int cnt = 0;
	vector<int> v;

	sort(B.begin(), B.end());


	for (int i : A) {
		if (!binary_search(B.begin(), B.end(), i)) {
			cnt++;
			v.push_back(i);
		}
	}

	cout << cnt << '\n';
	if (cnt == 0) return 0;
	sort(v.begin(), v.end());
	for (int i : v) {
		cout << i << " ";
	}
	cout << '\n';
	return 0;
}