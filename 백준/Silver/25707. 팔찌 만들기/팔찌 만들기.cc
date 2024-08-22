#include <bits/stdc++.h>

#define PII pair<int,int>
#define PIII pair<int,PII>

using namespace std;
typedef long long ll;

int n;
int arr[1000];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];
	sort(arr, arr + n);
	cout << 2 * (arr[n - 1] - arr[0]);
	return 0;
}