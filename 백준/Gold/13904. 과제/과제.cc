#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool compare(pair<int,int> a, pair<int,int> b){
	if (a.first == b.first){
		return a.second > b.second;
	}
	else{
		return a.first > b.first;
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int n,d,w,ans=0;
	int arr[1001] = {0};
	vector<pair<int,int>> v;
	
	cin>>n;
	
	for (int i=0;i<n;i++){
		cin>>d>>w;
		v.emplace_back(w,d);
	}
	
	sort(v.begin(), v.end(), compare);
	
	for (int i=0;i<n;i++){
		w = v[i].first;
		d = v[i].second;
		
		while (d){
			if (arr[d] == 0){
				arr[d] = 1;
				ans+=w;
				d=0;
			}
			
			else {
				d--;
			}
		}
	}
	
	cout<<ans;
}