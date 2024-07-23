#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	vector<string> v1, v2, v3;
	int n, m;
	string temp;
	cin >> n >> m;
	
	for (int i = 0; i < n; i++) {
		cin >> temp;
		v1.push_back(temp);
	}

	for (int i = 0; i < m; i++) {
		cin >> temp;
		v2.push_back(temp);
	}

	
	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());
	set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), back_inserter(v3));
	sort(v3.begin(), v3.end());

	cout << v3.size() << '\n';
	for (string s : v3) {
		cout << s << '\n';
	}



}