#include <iostream>
#include <algorithm>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int n, q,s, e, ans=0;
	cin>>n>>q;
	
	int arr[n+1] = {0};
	for (int i=1;i<=n;i++){
		cin>>arr[i];
		arr[i] = arr[i] ^ arr[i-1];
	}
	
	for (int i=0;i<q;i++){
		cin>>s>>e;
		
		ans = ans ^ (arr[e] ^ arr[s-1]);
	}
	
	cout<<ans;
	
	
	return 0;
}
