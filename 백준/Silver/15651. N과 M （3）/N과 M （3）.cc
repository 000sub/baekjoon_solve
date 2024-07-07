#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>
#include <map>
#include <cmath>

using namespace std;

vector<int> v;
int n,m;

void bt(int idx){
	if (idx == m) {
		for (int i: v) cout<<i<<" ";
		cout<<'\n';
		return;
	}
	
	for (int i=1; i<=n; i++) {
		v.push_back(i);
		bt(idx+1);
		v.pop_back();
	}
	
	
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin>>n>>m;
	bt(0);
}