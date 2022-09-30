#include <iostream>
#include <algorithm>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int n, ans=0;

	cin>>n;
	int arr[n];
	
	for (int i=0;i<n;i++) {
		cin>>arr[i];
	}
	
	sort(arr, arr+n);
	
	for (int i=0;i<n;i++){
		ans += arr[i]*(n-i);
	}
	
	cout<<ans<<'\n';
	
	
	return 0;
}
