#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#define PII pair<int,int>

using namespace std;
typedef long long ll;

set<char> s1({ '`','1','2','3','4','5','6','7','8','9','0','-','=' }),
s2({ 'Q','W','E','R','T','Y','U','I','O','P','[',']','\\' }),
s3({ 'A','S','D','F','G','H','J','K','L',';','\'' }),
s4({ 'Z','X','C','V','B','N','M',',','.','/' });

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	string s, ans = "";
	getline(cin, s);

	for (char c : s) {
		if (s1.count(c)) ans += '1';
		else if (s2.count(c)) ans += '2';
		else if (s3.count(c)) ans += '3';
		else if (s4.count(c)) ans += '4';
		else ans += '5';
	}

	cout << ans;

	return 0;
}