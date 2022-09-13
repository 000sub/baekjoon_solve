#include <iostream>
#include <algorithm>

using namespace std;

bool cmp(const pair<int,int> &a, const pair<int, int> &b){
	return a.first < b.first;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int t, n;
	cin>>t;
	
	for (int i=0; i<t;i++){	
		cin>>n;
		pair<int, int> arrp[n];
		
		for (int j=0;j<n;j++){
			int a, b;
			cin>>a>>b;
			arrp[j].first=a;
			arrp[j].second=b;
		}
		
		sort(arrp, arrp+n, cmp);
		
		int cnt = 1;
		int maxval = arrp[0].second;
		
		for (int j=1;j<n;j++){
			if (arrp[j].second <= maxval){
				cnt++;
				maxval = arrp[j].second;
			}
		}             
		
		cout<<cnt<<'\n';
	}
	return 0;
}