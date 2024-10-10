#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
#include <set>
#include <string>

#define PII pair<int,int>
using namespace std;

set<string> SET;
int N;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
    cin>>N;

	string a,b;
	for (int i=0; i<N; i++) {
		cin>>a>>b;
		if (b == "enter") {
			SET.insert(a);
		}
		else {
			SET.erase(a);
		}
	}

	for (auto it = SET.rbegin(); it != SET.rend(); ++it) {
		cout << *it << '\n';
	}

    return 0;
}