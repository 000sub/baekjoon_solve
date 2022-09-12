#include <iostream>
#include <algorithm>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int t, n;
	cin >>t;
	for (int i=0;i<t;i++){
		cin>>n;
		int dp[n+1][2] = {0};
		int arr[n+1][2];
		
		for (int j=0;j<2;j++){
			for (int k=1;k<n+1;k++){
				cin>>arr[k][j];
			}
		}
		dp[1][0] = arr[1][0];
		dp[1][1] = arr[1][1];
		
		for (int j=2;j<n+1;j++){
			dp[j][0] = max({dp[j-1][1], dp[j-2][0],dp[j-2][1]}) + arr[j][0];
			dp[j][1] = max({dp[j-1][0], dp[j-2][1],dp[j-2][0]}) + arr[j][1];
		}
		cout << max(dp[n][0], dp[n][1]) << '\n';
	}
	return 0;
}
