#include <bits/stdc++.h>

#define PII pair<int,int>
using namespace std;
typedef long long ll;

int A, B;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> A >> B;
	int lCnt = 0, rCnt = 0;

	while (A > 1 && B > 1) {
		if (A > B) {
			lCnt+= A/B;
			A%=B;
		}
		else {
			rCnt+=B/A;
			B%=A;
		}
	}
	if (A == 1) rCnt += B - 1;
	if (B == 1) lCnt += A - 1;
	cout << lCnt << ' ' << rCnt;
	return 0;
}