#include <iostream>
#include <algorithm>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int n,m,lo=0,hi=0;
	cin>>n>>m;
	int arr[n];
	for (int i=0;i<n;i++) cin>>arr[i];
	int val = 2000000001;
	
	sort(arr,arr+n);
	
	while (lo<=hi && hi < n){
		if (abs(arr[hi] - arr[lo]) < m){
			hi++;
		}
		else if (abs(arr[hi] - arr[lo]) == m){
			val = m;
			break;
		}
		else {
			val = min(val, abs(arr[hi] - arr[lo]));
			lo++;
		}
	}
	
	cout<<val;
	
	
	return 0;
}