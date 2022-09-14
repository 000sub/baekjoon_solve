#include <iostream>
#include <algorithm>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int n;
	cin>>n;
	int arr[n+1], dp[n+1] = {0};
	
	for (int i=1;i<=n;i++){
		cin>>arr[i];
	}
	
	dp[1] = 1;

	for (int i=2;i<=n;i++){
		int maxcnt = 0;
		for (int j=1;j<i;j++){
			if (arr[i] > arr[j] && dp[j] > maxcnt){
				maxcnt = dp[j];
			}
		}
		dp[i] = maxcnt+1;
	}
	
	int m = *max_element(dp,dp+n+1);
	cout<<n-m;
	return 0;
}
