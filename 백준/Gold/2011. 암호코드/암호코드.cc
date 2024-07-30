#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#define PII pair<int,int>

using namespace std;
typedef long long ll;

const ll mod = 1e6;

ll dp[5001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	string s;
	cin >> s;

	if (s[0] == '0') {
		cout << 0;
		return 0;
	}

	dp[0] = 1;
	if (stoi(s.substr(0, 2)) <= 26) dp[1]++;
	if (s[1] != '0') dp[1]++;

	for (int i = 2; i < s.size(); i++) {
		if (s[i] == '0' && s[i - 1] >= '3') {
			cout << 0;
			return 0;
		}
		if (s[i - 1] != '0' && stoi(s.substr(i - 1, 2)) <= 26) dp[i] += dp[i - 2];
		dp[i] %= mod;
		if (s[i] != '0') dp[i] += dp[i - 1];
		dp[i] %= mod;
	}

	cout << dp[s.size() - 1];


	return 0;
}