#include <bits/stdc++.h>
#include <unordered_set>
#define PII pair<int,int>
using namespace std;

int N;
string str;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	while (N--) {
		cin >> str;
		sort(str.begin(), str.end());
		do {
			cout << str << '\n';
		} while (next_permutation(str.begin(), str.end()));
	}
	
	return 0;
}