#include <bits/stdc++.h>
#define PII pair<int,int>
#define PIII pair<int,PII>

using namespace std;
typedef long long ll;
const int INF = 1e9;

int N, temp;
int ans[1001];


int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> temp;
			ans[i] |= temp;
			ans[j] |= temp;
		}
	}

	for (int i = 0; i < N; i++) cout << ans[i] << " ";
	return 0;
}