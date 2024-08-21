#include <bits/stdc++.h>

#define PII pair<int,int>
#define PIII pair<int,PII>

using namespace std;
typedef long long ll;

int n;
vector<int> v, ans;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;

	int temp;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		v.push_back(temp);
	}

	for (int i = 0; i < v.size(); i++) {
		ans.push_back(v[i]);
		i += v[i] - 1;
	}

	for (int i : ans) cout << i << " ";
	cout << '\n';

	return 0;
}