#include <bits/stdc++.h>

#define PII pair<int,int>
using namespace std;
typedef long long ll;

int M;
int op, x, w;

map<int, int> ball_chest;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> M;
	while (M--) {
		cin >> op;
		if (op == 1) {
			cin >> x >> w;
			ball_chest[w] = x;
		}
		else {
			cin >> w;
			cout << ball_chest[w] << '\n';
		}
	}
	
	return 0;
}