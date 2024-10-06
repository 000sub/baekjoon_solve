#include <bits/stdc++.h>

#define PII pair<int,int>
using namespace std;
typedef long long ll;

int N, M, ans = 0;
PII infos[21];

void dfs(int idx, int days, int pages) {
	ans = max(ans, pages);
	if (idx == M) return;
	
	int curDay = infos[idx].first;
	int curPage = infos[idx].second;

	if (days + infos[idx].first <= N) dfs(idx + 1, days + curDay, pages + curPage);
	dfs(idx + 1, days, pages);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> infos[i].first >> infos[i].second;
	}
	sort(infos, infos + M, [](PII& a, PII& b) {return a.second > b.second; });
	dfs(0, 0, 0);
	cout << ans;

	return 0;
}