#include <bits/stdc++.h>
using namespace std;

int N, maxCnt = 0;
string str;
vector<string> v;
map<string, vector<int>> MAP;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> str;
		v.push_back(str);

		string temp = "";
		
		for (int j = 0; j < str.size(); j++) {
			temp += str[j];
			if (MAP.count(temp)) maxCnt = max(maxCnt, (int)temp.size());
			MAP[temp].push_back(i);
		}
	}

	int minPrefixIdx = 1e9;
	string minPrefix;
	for (auto& p : MAP) {
		if (p.second.size() >= 2 && p.first.size() == maxCnt) {
			if (minPrefixIdx > p.second[0]) {
				minPrefixIdx = p.second[0];
				minPrefix = p.first;
			}
		}
	}
	cout << v[MAP[minPrefix][0]] << '\n' << v[MAP[minPrefix][1]];

	return 0;
}