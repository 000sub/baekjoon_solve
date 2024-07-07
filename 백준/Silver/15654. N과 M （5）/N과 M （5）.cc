#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> nums, v;
bool visited[9];
int n,m;

void bt(int idx){
	if (idx == m) {
		for (int i: v) cout<<i<<" ";
		cout<<'\n';
		return;
	}
	
	for (int i=0; i<n; i++) {
		if (!visited[i]) {
			v.push_back(nums[i]);
				visited[i] = true;
				bt(idx+1);
				v.pop_back();
				visited[i] = false;
		}
		
	}
	
	
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin>>n>>m;
	int t;
	
	for (int i=0; i<n; i++) {
		cin>>t;
		nums.emplace_back(t);
	}
	
	sort(nums.begin(), nums.end());
	
	bt(0);
}