#include <bits/stdc++.h>
#define PII pair<int, int>

using namespace std;
typedef long long ll;

int N, B, C;
int A[1000001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) cin >> A[i];
	cin >> B >> C;

	ll ans = N;
	for (int i = 0; i < N; i++) {
		A[i] -= B;
		if (A[i] > 0) {
			ans += A[i] / C + (A[i] % C ? 1 : 0);
		}
	}
	cout << ans;
	return 0;
}