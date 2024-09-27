#include <bits/stdc++.h>

#define PII pair<int,int>
#define PIII pair<int,PII>
using namespace std;
typedef long long ll;

string S, T;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> S >> T;

	while (T.size() > S.size()) {
		char ch = T.back();
		T = T.substr(0, T.size() - 1);
		if (ch == 'B') {
			reverse(T.begin(), T.end());
		}
	}
	if (S == T) cout << 1;
	else cout << 0;
	return 0;
}