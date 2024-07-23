#include <iostream>
#include <algorithm>
#include <string>
#define PII pair<int,int>
using namespace std;

int st[10001];
int len = 0;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	int n, num;
	string op;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> op;
		if (op == "push") { 
			cin >> num; 
			st[len++] = num;
		}
		else if (op == "top") {
			if (len == 0) {
				cout << -1 << '\n';
			}
			else {
				cout << st[len-1] << '\n';
			}
		}
		else if (op == "size") {
			cout << len << '\n';
		}
		else if (op == "empty") {
			len == 0 ? cout << 1 : cout << 0;
			cout << '\n';
		}
		else if (op == "pop") {
			if (len == 0) {
				cout << -1 << '\n';
			}
			else {
				cout << st[--len] << '\n';
			}
		}

	}



	return 0;
}