#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, t, p, dp[17];
    vector<pair<int,int>> v;

    cin>>n;

    v.emplace_back(0,0);
    for (int i=0; i<n; i++){
        cin>>t>>p;
        v.emplace_back(t,p);
    }

    memset(dp, 0, sizeof(dp));

    for (int i=1; i<=n; i++){
        if (i + v[i].first <= n+1){
            dp[i + v[i].first] = max(dp[i + v[i].first], dp[i] + v[i].second);
        }

        dp[i+1] = max(dp[i+1], dp[i]);
    }

    cout<<dp[n+1]<<'\n';


    return 0;
}
