#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
#include <set>
#include <string>
#include <map>

#define PII pair<int,int>
using namespace std;

map<string, int> stud_order;
map<int, string> order_stud;
int K,L;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
    cin>>K>>L;
	string s;
	for (int i=0; i<L; i++) {
		cin>>s;
		if (stud_order.count(s)) {
			int prevIdx = stud_order[s];
			order_stud.erase(prevIdx);
		}
		order_stud[i] = s;
		stud_order[s] = i;
	}

	int cnt = 0;
	for (auto& p : order_stud) {
		if (++cnt > K) break;
		cout << p.second << '\n';
	}

    return 0;
}