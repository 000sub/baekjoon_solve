#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
	int n;
	cin>>n;
	vector<pair<int,int>> v;
	
	for (int i=0;i<n;i++){
		int t, s;
		cin>>t>>s;
		v.emplace_back(s,t);
	}
	
	sort(v.begin(), v.end());
	
	int s, cur;
	s = v[0].first - v[0].second;
	cur = v[0].first;
	if (s<0){
		cout<<-1;
		return 0;
	}
	
	for (int i=1;i<n;i++){
		cur+=v[i].second;
		
		if (cur>v[i].first){
			s -= cur - v[i].first;
			cur = v[i].first;
			
			if (s<0){
				cout<<-1;
				return 0;
			}
			
		}
	}
	
	cout<<s;
	
}