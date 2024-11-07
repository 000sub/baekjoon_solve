#include <bits/stdc++.h>
#include <unordered_set>
#define PII pair<int,int>
using namespace std;

int N, ans = 0;
int arr[30001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) cin >> arr[i];

	int maxH = 0, cnt = 0;
	for (int i = 1; i < N; i++) {
		if (arr[maxH] < arr[i]) {
			maxH = i;
			cnt = 0;
		}
		else cnt++;
		ans = max(ans, cnt);
	}
	cout << ans;

	
	return 0;
}