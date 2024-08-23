#include <bits/stdc++.h>

#define PII pair<int,int>
#define PIII pair<int,PII>

using namespace std;
typedef long long ll;

int n;
string s;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> s;
	map<char, int> um;

	for (int i = 0; i < s.size(); i++) {
		if (n % 2 && i == n / 2) continue;
		um[s[i]]++;
	}

	for (auto& entry : um) {
		if (entry.second % 2) {
			cout << "No";
			return 0;
		}
	}

	cout << "Yes";
	return 0;
}