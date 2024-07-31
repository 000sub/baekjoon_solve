#include <bits/stdc++.h>

#define PII pair<int,int>

using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	string s;

	while (getline(cin, s)) {
		if (s == "#") {
			return 0;
		}

		int shift = s[s.size() - 1] - 'A';

		for (int i = 0; i < s.size(); i++) {
			char c = s[i];
			int aIdx;
			bool isCapital = false;

			if ('a' <= c && c <= 'z') aIdx = c - 'a';
			else if ('A' <= c && c <= 'Z') {
				aIdx = c - 'A';
				isCapital = true;
			}
			else continue;
			
			aIdx = (aIdx - shift + 26) % 26;

			s[i] = isCapital ? 'A' + aIdx : 'a' + aIdx;
		}

		s.pop_back();

		cout << s << '\n';
	}
	
	return 0;
}