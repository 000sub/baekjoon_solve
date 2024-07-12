#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
#include <cstring>
#include <cmath>
#include <map>
typedef long long ll;
using namespace std;


map<string, int> _map;
vector<string> v;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	int n,m;
	cin>>n>>m;
	
	string s;
	
	for (int i=0; i<n; i++) {
		cin>>s;
		_map[s] = i+1;
		v.push_back(s);
	}
	
	for (int i=0; i<m; i++) {
		cin>>s;
		if (isalpha(s[0])) cout<<_map[s]<<'\n';
		else cout<<v[stoi(s)-1]<<'\n';
	}
}