#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int d, ve, ans=0;
	vector<pair<int,int>> v;
	
	for (int i=0;i<11;i++){
		cin>>d>>ve;
		
		v.emplace_back(d, ve);
	}
	
	sort(v.begin(), v.end());
	
	int t=0;
	for (int i=0;i<11;i++){
		d = v[i].first;
		ve = v[i].second;
		t+=d;
		ans += t+20*ve;
		
	}
	
	cout<<ans;
}