#include <bits/stdc++.h>
#include <unordered_set>
#define PII pair<int,int>
using namespace std;

int T, M;
priority_queue<int> maxH;
priority_queue<int, vector<int>, greater<>> minH;
vector<int> ans;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> T;
	while (T--) {
		cin >> M;
		for (int i = 0, k; i < M; i++) {
			cin >> k;
			i % 2 ? minH.push(k) : maxH.push(k);

			if (!minH.empty() && !maxH.empty() && minH.top() < maxH.top()) {
				int tempMin = minH.top();
				int tempMax = maxH.top();
				minH.pop(); maxH.pop();
				minH.push(tempMax);  maxH.push(tempMin);
			}

			if (i % 2 == 0) {
				ans.push_back(maxH.top());
			}
		}
		cout << ans.size() << '\n';
		for (int i = 0, cnt = 1; i < ans.size(); i++, cnt++) {
			cout << ans[i] << ' ';
			if (cnt == 10) cnt=0, cout << '\n';
		}
		cout << '\n';
		minH = priority_queue<int, vector<int>, greater<>>();
		maxH = priority_queue<int>();
		ans.clear();
	}
	
	return 0;
}