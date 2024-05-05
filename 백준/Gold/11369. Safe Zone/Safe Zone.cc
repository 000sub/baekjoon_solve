#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>
using namespace std;

int dp[51][51];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	int N,P,Q,J,K, cnt;
	while (true) {
		cnt = 0;
		memset(dp, 0, sizeof(dp));
		cin>>N>>P>>Q>>J>>K;
		
		if (N==0&&P==0&&Q==0&&J==0&&K==0) return 0;
    
    	dp[J][0] = 1;
	    for (int i=1; i<=K; i++) {
	    	for (int j=0; j<N; j++) {
	    		if (j == 0)
	    			dp[j][i] += dp[j+1][i-1];
	   			else if (j == N-1)
	   				dp[j][i] += dp[j-1][i-1];
	   			else
	   				dp[j][i] += dp[j-1][i-1] + dp[j+1][i-1];
			}
		}
		
		for (int i=P;i<=Q;i++) {
			cnt += dp[i][K];
		}
		
		cout<<cnt<<'\n';
		
	}
    
    return 0;
}