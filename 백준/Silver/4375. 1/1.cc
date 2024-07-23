#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define PII pair<int,int>
using namespace std;
typedef long long ll;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	int n;
	while (cin >> n) {
		int num = 0;
		for (int i = 1; i <= n; i++) {
			num = num * 10 + 1;
			num %= n;
			if (num == 0) {
				cout << i << '\n';
				break;
			}
		}
	}

	return 0;
}