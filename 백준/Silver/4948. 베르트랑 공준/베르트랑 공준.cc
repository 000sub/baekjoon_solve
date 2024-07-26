#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#define PII pair<int,int>

using namespace std;
typedef long long ll;

bool arr[250001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n;

	fill(arr, arr + 250001, true);

	for (int i = 2; i <= 250000; i++) {
		if (!arr[i]) continue;
		for (int j = 2; i*j <= 250000; j++) {
			arr[i*j] = false;
		}
	}

	while (cin >> n) {
		if (n == 0) break;
		int cnt = 0;
		for (int i = n + 1; i <= 2 * n; i++) {
			if (arr[i]) cnt++;
		}

		cout << cnt << '\n';
	}

	return 0;
}