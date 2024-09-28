#include <bits/stdc++.h>
#include <unordered_map>

#define PII pair<int,int>
using namespace std;
typedef long long ll;

int N, Q;
unordered_map<int, vector<int>> Left, Right;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	int a, b;
	for (int i = 0; i < N; i++) {
		cin >> a >> b;
		Left[a].push_back(b);
		Right[b].push_back(a);
	}

	for (auto& p : Left) sort(p.second.begin(), p.second.end());
	for (auto& p : Right) sort(p.second.begin(), p.second.end());

	cin >> Q;
	for (int i = 0; i < Q; i++) {
		cin >> a >> b;
		if (Left[a].empty() || Right[b].empty()) {
			cout << -1 << '\n';
			continue;
		}

		int Ridx = lower_bound(Left[a].begin(), Left[a].end(), b) - Left[a].begin();
		int Lidx = lower_bound(Right[b].begin(), Right[b].end(), a) - Right[b].begin();
		int ans = -1;
		if (Ridx != Left[a].size() && Left[a][Ridx] == b && Lidx != Right[b].size() && Right[b][Lidx] == a) ans = 1;
		else if (Left[a].back() > b && Right[b].front() < a) ans = 2;

		cout << ans << '\n';
	}


	return 0;
}