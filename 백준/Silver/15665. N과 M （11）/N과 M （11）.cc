#include <bits/stdc++.h>
#define PII pair<int,int>
#define PIII pair<int,PII>

using namespace std;
typedef long long ll;
const int INF = 1e9;

int N, M, cnt[10001];
vector<int> v, ans;


void bt(int idx) {
	if (idx == M) {
		for (int i : ans) cout << i << " ";
		cout << '\n';
		return;
	}

	for (auto& elem : v) {
		ans.push_back(elem);
		bt(idx + 1);
		ans.pop_back();
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> N >> M;

	int temp;
	for (int i = 0; i < N; i++) {
		cin >> temp;
		if (cnt[temp] == 0) v.push_back(temp);
		cnt[temp]++;
	}
	sort(v.begin(), v.end());
	bt(0);
	return 0;
}