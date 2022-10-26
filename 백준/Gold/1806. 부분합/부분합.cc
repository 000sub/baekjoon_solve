#include <iostream>
#include <algorithm>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int n,s,lo=0,hi=0;
	cin>>n>>s;
	int arr[n];
	for (int i=0;i<n;i++) cin>>arr[i];
	
	int sum = arr[0], len = n+1;
	
	while (1){
		if (lo>hi || hi==n) break;
		if (sum >= s){
			len= min(len, hi-lo+1);
			sum-=arr[lo++];
		}
		else {
			sum+=arr[++hi];
		}
	}
	
	if (len==n+1) cout<<0;
	else cout<<len;
	
	return 0;
}