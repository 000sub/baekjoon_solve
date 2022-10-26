#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int n, m, s, e, cnt=0, cursum=0;
	cin>>n>>m;
	int arr[n+1];
	
	for (int i=1;i<=n;i++){
		cin>>arr[i];
	}
	
	s=1;
	e=1;
	while (s<=n | e<=n){
		if (cursum==m){
			cnt++;
			s++;
			e=s;
			cursum=0;
		}
		
		if (cursum>m){
			s++;
			e=s;
			cursum=0;
		}
		
		e++;
		cursum+=arr[e-1];
	}
	cout<<cnt;
	return 0;
	
}