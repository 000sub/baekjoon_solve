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

	ll ans = 0;
	for (int i = 0; i < n; i++) {
		if (i == s.size()) break;

		int gap = s[i] - 'a';
		if (gap == 0) ans++;
		else {
			ll k = 1, temp = 0;
			for (int j = 0; j < n - i; j++) {
				temp += k;
				k *= 26;
			}
			ans += temp * gap + 1;
		}
	}
	cout << ans;
	return 0;
}