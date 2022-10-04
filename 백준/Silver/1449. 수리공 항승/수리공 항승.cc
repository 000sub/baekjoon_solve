#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int n,l,ans=1;
	cin>>n>>l;
	
	vector<int> v;
	for (int i=0;i<n;i++){
		int temp;
		cin>>temp;
		v.push_back(temp);
	}
	
	sort(v.begin(), v.end());
	
	int dist = 0;
	for (int i=1;i<n;i++){
		dist += v[i]-v[i-1];
		if (l<=dist){
			ans++;
			dist = 0;
		}
	}
	
	
	cout<<ans;
	
}