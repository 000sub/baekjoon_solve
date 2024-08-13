#include <bits/stdc++.h>
#define PII pair<int,int>

using namespace std;

bool isPrime[10000];
int n;

bool check(int num) {
	if (num < 10000) return isPrime[num];

	for (int i = 2; i*i <= num; i++) {
		if (!isPrime[i]) continue;
		if (num % i == 0) return false;
	}

	return true;
}

void BT(int num, int size) {
	if (size == n) {
		cout << num << '\n';
		return;
	}

	for (int i = 0; i <= 9; i++) {
		if (check(num * 10 + i)) BT(num * 10 + i, size + 1);
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;

	memset(isPrime, true, sizeof(isPrime));

	isPrime[1] = false;

	for (int i = 2; i < 10000; i++) {
		if (!isPrime[i]) continue;
		for (int j = 2 * i; j < 10000; j += i) isPrime[j] = false;
	}

	BT(2, 1);
	BT(3, 1);
	BT(5, 1);
	BT(7, 1);

	return 0;
}