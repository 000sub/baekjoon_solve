#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#define PII pair<int,int>
using namespace std;

vector<PII> H, C;
vector<PII> selected;
int n, m, temp, ans = 1e9;

int calc() {
	int sum = 0;
	for (PII& h : H) {
		int dist = 1e9;
		for (PII& p : selected) {
			dist = min(dist, abs(h.first - p.first) + abs(h.second - p.second));
		}

		sum += dist;
	}
	return sum;
}

void BT(int idx, int cnt) {

	if (cnt == m) {
		int sum = calc();
		ans = min(ans, sum);
		return;
	}

	for (int i = idx; i < C.size(); i++) {
		selected.push_back(C[i]);
		BT(i+1, cnt + 1);
		selected.pop_back();
		BT(i+1, cnt);
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> temp;
			if (temp == 1) H.emplace_back(i, j);
			else if (temp == 2) C.emplace_back(i, j);
		}
	}

	BT(0, 0);

	cout << ans;

	return 0;
}