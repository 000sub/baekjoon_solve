#include <bits/stdc++.h>

#define PII pair<int,int>
using namespace std;
typedef long long ll;
//typedef unsigned long long ll;

int N, M;
ll T[100001];


bool check(ll t) {
	ll sum = 0;
	for (int i = 0; i < N; i++) {
		sum += t / T[i];
		if (sum >= M) return true;
	}
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; i++) cin >> T[i];

	ll lo = 0, hi = 1e18 + 1;

	while (lo <= hi) {
		ll mid = (lo + hi) / 2;

		if (!check(mid)) lo = mid + 1;
		else hi = mid - 1;
	}
	cout << lo;
	
	return 0;
}