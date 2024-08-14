#include <bits/stdc++.h>
#define PII pair<int,int>

using namespace std;

int n;
int arr[101][101];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	int a, b;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		for (int j = 0; j < 10; j++) {
			fill(arr[a + j] + b, arr[a + j] + b + 10, true);
		}
	}

	int ans = 0;

	for (int i = 1; i <= 100; i++) {
		for (int j = 1; j <= 100; j++) {
			if (arr[i][j]) ans++;
		}
	}

	cout << ans;

	return 0;
}