#include <iostream>
#include <algorithm>
#define MAX 1000000
using namespace std;


int n,k;
int arr[101], dp[101][10001];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	
	
	cin>>n>>k;
	
	for (int i=1;i<=n;i++){
		cin>>arr[i];
	}
	
	for (int i=0;i<=n;i++){
		for (int j=0;j<=k;j++){
			dp[i][j] = MAX;
		}
	}
	
	for (int i=1;i<=n;i++){
		dp[i][0] = 0;
		for (int j=0; j<=k; j++){
			if (i<n) dp[i+1][j] = min(dp[i+1][j], dp[i][j]);
			
			if (j+arr[i] <= k){
				dp[i][j+arr[i]] = min(dp[i][j]+1, dp[i][j+arr[i]]);
			}
		}
	}
	
	if (dp[n][k] == MAX) cout<<-1<<'\n';
	else cout<<dp[n][k]<<'\n';
	
	
	return 0;
}