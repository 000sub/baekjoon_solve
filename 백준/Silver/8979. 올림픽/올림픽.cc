#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

typedef struct nation {
	int idx;
	int gold;
	int silver;
	int bronze;

	bool equals(struct nation other) {
		return this->gold == other.gold && this->silver == other.silver && this->bronze == other.bronze;
	}
} Nation;

Nation nations[1001];

bool cmp(Nation& a, Nation& b) {
	if (a.gold != b.gold) return a.gold > b.gold;
	if (a.silver != b.silver) return a.silver > b.silver;
	return a.bronze > b.bronze;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> nations[i].idx >> nations[i].gold >> nations[i].silver >> nations[i].bronze;
	}

	sort(nations, nations + n, cmp);

	int rank = 1;
	Nation prev = nations[0];

	if (prev.idx == k) {
		cout << rank;
		return 0;
	}

	for (int i = 1; i < n; i++) {
		Nation cur = nations[i];

		if (cur.equals(prev)) {
			if (cur.idx == k) {
				cout << rank;
				return 0;
			}
			else {
				prev = cur;
				continue;
			}
		}

		prev = cur;
		rank = i+1;

		if (cur.idx == k) {
			cout << rank;
			return 0;
		}
	}
	return 0;
}