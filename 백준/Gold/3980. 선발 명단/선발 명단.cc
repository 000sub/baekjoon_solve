#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <set>
#define PII pair<int,int>

using namespace std;
typedef long long ll;
int arr[11][11];
bool visited[11];
vector<int> v;
int ans = 0;

void check() {
	int res = 0;
	for (int i : v) res += i;
	ans = max(ans, res);
}

void BT(int idx) {
	if (idx == 11 && v.size() == 11) {
		check();
		return;
	}

	for (int i = 0; i < 11; i++) {
		if (!visited[i] && arr[idx][i]) {
			visited[i] = true;
			v.push_back(arr[idx][i]);
			BT(idx + 1);
			v.pop_back();
			visited[i] = false;
		}
	}

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int t;
	cin >> t;

	while (t--) {
		memset(visited, false, sizeof(visited));
		v.clear();
		ans = 0;

		for (int i = 0; i < 11; i++)
			for (int j = 0; j < 11; j++)
				cin >> arr[i][j];

		BT(0);

		cout << ans << '\n';
	}
	

	return 0;
}