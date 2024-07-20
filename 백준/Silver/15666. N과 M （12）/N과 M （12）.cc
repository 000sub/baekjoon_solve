#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <set>

using namespace std;

int arr[9];
int n, m;
vector<int> v;
set<vector<int>> s;

void bt() {
	if (v.size() == m) {
		if (!s.count(v)) {
			for (int i : v) cout<<i<<' ';
			cout<<'\n';
			s.insert(v);
		}
		return;
	}
	
	for (int i=0; i<n; i++) {
		if (!v.empty() && v[v.size()-1] > arr[i]) continue;
		v.push_back(arr[i]);
		bt();
		v.pop_back();
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	
	cin>>n>>m;
	
	for (int i=0; i<n; i++) cin>>arr[i];
	sort(arr, arr+n);
	
	bt();
	
	return 0;
}
