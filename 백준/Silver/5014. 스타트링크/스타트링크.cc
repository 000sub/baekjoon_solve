#include <bits/stdc++.h>
#define PII pair<int, int>

using namespace std;

int f, s, g, u, d;
bool visited[1000001];

int main() {
	ios::sync_with_stdio;
	cin.tie(0);

	cin >> f >> s >> g >> u >> d;

	queue<PII> q;
	q.push({ s, 0 });
	visited[s] = true;
	while (!q.empty()) {
		int cur = q.front().first;
		int cnt = q.front().second;
		q.pop();

		if (cur == g) {
			cout << cnt;
			exit(0);
		}

		if (cur - d >= 1 && !visited[cur - d]) {
			visited[cur - d] = true;
			q.push({ cur - d, cnt + 1 });
		}
		if (cur + u <= f && !visited[cur + u]) {
			visited[cur + u] = true;
			q.push({ cur + u, cnt + 1 });
		}
	}

	cout << "use the stairs";
	
	return 0;
}