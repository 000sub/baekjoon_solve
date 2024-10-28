#include <bits/stdc++.h>
#include <unordered_set>
#define PII pair<int,int>
using namespace std;

int N, ans = 0;
vector<int> v[5001];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	for (int i = 0, a, b; i < N; i++) {
		cin >> a >> b;
		v[b].push_back(a);
	}

	for (int i = 1; i <= N; i++) {
		sort(v[i].begin(), v[i].end());
		for (int j = 0; j < v[i].size(); j++) {
			int dist = (j == v[i].size() - 1) ? v[i][j] - v[i][j - 1] : (j == 0) ? v[i][j+1] - v[i][j] : min(v[i][j] - v[i][j - 1], v[i][j + 1] - v[i][j]);
			ans += dist;
		}
	}
	cout << ans;
	
	return 0;
}