#include <bits/stdc++.h>
#define PII pair<int,int>
#define PIII pair<int,PII>

using namespace std;
typedef long long ll;
const int INF = 1e9;

int N, M;
vector<int> v, ans;


void bt(string s, int idx) {
	if (idx == M) {
		cout << s << '\n';
		return;
	}

	for (auto& elem : v) {
		bt(s + to_string(elem) + " ", idx + 1);
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> N >> M;

	int temp;
	for (int i = 0; i < N; i++) {
		cin >> temp;
		v.push_back(temp);
	}
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	bt("", 0);
	return 0;
}