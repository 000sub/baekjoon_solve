#include <bits/stdc++.h>

#define PII pair<int,int>
using namespace std;
typedef long long ll;

int A, B, V;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> A >> B >> V;
	int ans = (V - B) % (A - B) ? (V - B) / (A - B) + 1 : (V - B) / (A - B);
	cout << ans;
	return 0;
}