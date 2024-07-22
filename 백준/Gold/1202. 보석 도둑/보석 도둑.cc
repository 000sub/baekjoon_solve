#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define PII pair<int,int>
using namespace std;
typedef long long ll;

int n, k;
PII J[300001];
int C[300001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		J[i] = { a,b };
	}
	for (int i = 0; i < k; i++) cin >> C[i];

	sort(J, J + n);
	sort(C, C + k);
	
	int jIdx = 0;
	ll ans = 0;
	priority_queue<int> pq;
	for (int i = 0; i < k; i++) {
		while (jIdx < n && J[jIdx].first <= C[i]) pq.push(J[jIdx++].second);

		if (!pq.empty()) {
			ans += pq.top();
			pq.pop();
		}
	}

	cout << ans;
	return 0;
}