#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

const int MOD = 10007;
int dp[1001];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	int n;
	cin>>n;
	dp[1] = 1; dp[2] = 3;
	for (int i=3; i<=n; i++) dp[i] = (dp[i-1] + dp[i-2] * 2) % MOD;
	cout<<dp[n];
}