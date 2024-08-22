#include <bits/stdc++.h>

#define PII pair<int,int>
#define PIII pair<int,PII>

using namespace std;
typedef long long ll;

int n, k;
int arr[4243];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> k;
	for (int i = 1; i <= n; i++) arr[i] = i;
	if (k == 0) {
		for (int i = 1; i <= n; i++) cout << arr[i] << " ";
		cout << '\n';
		return 0;
	}
	for (int i = 1; i <= n, k>0; i++) {
		int d = min(k, n - i);
		k -= d;
		swap(arr[i], arr[i + d]);
		sort(arr + i + 1, arr +n+1);
	}
	for (int i = 1; i <= n; i++) cout << arr[i] << " ";
	cout << '\n';

	return 0;
}