#include <bits/stdc++.h>
#include <unordered_set>
#define PII pair<int,int>
using namespace std;

int arr[5];
int ans = 1e9;
vector<int> v;

int gcd(int x, int y) {
	return x % y == 0 ? y : gcd(y, x%y);
}

void check() {
	int temp = v[0] * v[1] / gcd(v[0], v[1]);
	int mul = v[2] * temp / gcd(v[2], temp);
	ans = min(ans, mul);
}

void bt(int idx, int cnt) {
	if (cnt == 3) {
		check();
		return;
	}

	for (int i = idx; i < 5; i++) {
		v.push_back(arr[i]);
		bt(i + 1, cnt + 1);
		v.pop_back();
		bt(i + 1, cnt);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	for (int i = 0; i < 5; i++) {
		cin >> arr[i];
	}

	bt(0, 0);
	cout << ans;
	
	return 0;
}