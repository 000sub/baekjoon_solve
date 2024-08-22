#include <bits/stdc++.h>

#define PII pair<int,int>
#define PIII pair<int,PII>

using namespace std;
typedef long long ll;

int n;
int A[22], B[22];
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n * 2; i++) cin >> A[i];
	for (int i = 0; i < n * 2; i++) cin >> B[i];

	bool flag = true;
	int M = 0;

	for (int i = 0; i < n * 2; i += 2) {
		int s1 = A[i], e1 = A[i + 1], s2 = B[i], e2 = B[i + 1];
		if (s1 < e2 && s2 < e1) M++;
		else if (s1 != e2 && s2 != e1) {
			flag = false; 
			break;
		}
	}

	flag ? cout<<M : cout<<-1;
	return 0;
}