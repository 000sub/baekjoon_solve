#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <set>

using namespace std;

int arr[9];
bool visited[9];
int n, m;
vector<int> v;
set<vector<int>> s;

void bt(int idx,int len) {
	if (len == m) {
		if (!s.count(v)) {
			for (int i : v) cout<<i<<' ';
			cout<<'\n';
			s.insert(v);
		}
		return;
	}
	
	for (int i=0; i<n; i++) {
		if (!visited[i]) {
			v.push_back(arr[i]);
			visited[i] = true;
			bt(idx+1, len+1);
			v.pop_back();
			visited[i] = false;
		}
		
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	
	cin>>n>>m;
	
	for (int i=0; i<n; i++) cin>>arr[i];
	sort(arr, arr+n);
	
	bt(0, 0);
	
	return 0;
}
