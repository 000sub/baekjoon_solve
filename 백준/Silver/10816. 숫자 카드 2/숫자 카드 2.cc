#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <unordered_map>
#include <set>
#include <queue>
#include <stack>
#define PII pair<int,int>

using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n, m, temp;
	unordered_map<int, int> MAP;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		MAP[temp]++;
	}
	cin >> m;
	for (int i = 0; i < m - 1; i++) {
		cin >> temp;
		cout << MAP[temp] <<' ';
	}
	cin >> temp;
	cout << MAP[temp];
	

	return 0;
}