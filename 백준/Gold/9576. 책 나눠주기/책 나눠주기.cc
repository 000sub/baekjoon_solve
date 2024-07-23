#include <iostream>
#include <algorithm>
#include <cstring>
#define PII pair<int,int>
using namespace std;

bool visited[1001];
PII stud[1001];

bool cmp(PII& a, PII& b) {
	if (a.second != b.second) return a.second < b.second;
	return a.first < b.first;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int t, n, m;
	cin >> t;

	while (t--) {
		memset(visited, false, sizeof(visited));
		cin >> n >> m;
		for (int i = 0; i < m; i++) cin >> stud[i].first >> stud[i].second;
		sort(stud, stud + m, cmp);

		int ans = 0;

		for (int s = 0; s < m; s++) {
			for (int i = stud[s].first; i <= stud[s].second; i++) {
				if (!visited[i]) {
					visited[i] = true;
					ans++;
					break;
				}
			}
		}

		cout << ans<<'\n';
	}
	

	return 0;
}