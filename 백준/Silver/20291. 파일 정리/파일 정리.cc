#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <unordered_map>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <sstream>
#define PII pair<int,int>

using namespace std;
typedef long long ll;

vector<string> split(string s, char delimiter) {
	istringstream iss(s);
	string buf;
	vector<string> res;

	while (getline(iss, buf, delimiter)) res.push_back(buf);

	return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n;
	string s;
	map<string, int> MAP;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s;
		vector<string> v = split(s, '.');
		MAP[v[v.size() - 1]]++;
	}

	for (auto& e : MAP) {
		cout << e.first << ' ' << e.second << '\n';
	}

	return 0;
}