#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <string>
#include <set>

#define PII pair<int,int>
using namespace std;

int N;
set<string> SET;
int main() {
    ios::sync_with_stdio(false);
	cin.tie(0);

	cin>>N;
	string s;
	int ans = 0;
	for (int i=0; i<N; i++) {
		cin>>s;
		if (s == "ENTER") SET.clear();
		else if (!SET.count(s)) {
			ans++;
			SET.insert(s);
		}
	}
	cout<<ans;

    return 0;
}