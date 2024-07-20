#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>

using namespace std;

int n;
multimap<string, string> m;
string src, tgt;

void dfs(string k, string t) {
	for (auto it = m.lower_bound(k); it != m.upper_bound(k); it++) {
		if (it->second == t) {
			cout<<1;
			exit(0);
		}
		dfs(it->second, t);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	cin>>n;
	string a,b;
	
	for (int i=0; i<n-1; i++)  {
		cin>>a>>b;
		m.insert({b,a});
	}
	
	cin>>src>>tgt;
	
	dfs(src, tgt);
	dfs(tgt, src);
	
	cout<<0;
	return 0;
}
