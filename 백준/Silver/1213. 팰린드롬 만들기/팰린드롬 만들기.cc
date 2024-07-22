#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int A[26];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	string s, ans = "";
	cin >> s;

	for (char c : s) A[c - 'A']++;

	bool isOdd = false;
	char oddC;

	for (int i = 0; i < 26; i++) {
		if (A[i] % 2) {
			if (isOdd) {
				cout << "I'm Sorry Hansoo";
				return 0;
			}
			isOdd = true;
			oddC = i + 'A';
		}
		if (A[i] > 0) {
			for (int j = 0; j < A[i] / 2; j++) ans += (char)i + 'A';
		}
		
	}

	cout << ans;
	if (isOdd) cout << oddC;
	reverse(ans.begin(), ans.end());
	cout << ans;


	return 0;
}