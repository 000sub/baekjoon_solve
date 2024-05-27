#include <string>
#include <vector>
#define ll long long
#define MOD 1000000007
using namespace std;

ll dp[5001];

int solution(int n) {    
    if (n%2) return 0;
    
    dp[2] = 3;
    
    for (int i=4; i<=n;i+=2) {
        dp[i] = dp[i-2] * 3;
        for (int j=i-4; j>=2; j-=2) {
            dp[i] += dp[j] * 2;
        }
        dp[i] += 2;
        dp[i] %= MOD;
    }
    
    return dp[n];
}