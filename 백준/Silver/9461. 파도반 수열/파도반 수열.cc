#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);


    int t, n;
    long long dp[101];
    memset(dp, 0, sizeof(dp));

    for (int i=1;i<=3;i++) dp[i] = 1;
    for (int i=4;i<=5;i++) dp[i] = 2;

    for (int i=6;i<=100;i++){
        dp[i] = dp[i-5] + dp[i-1];
    }
    cin>>t;

    for (int i=0; i<t; i++){
        cin>>n;

        cout<<dp[n]<<'\n';
    }


    return 0;
}
