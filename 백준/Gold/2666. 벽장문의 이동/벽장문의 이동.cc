#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
#include <vector>

using namespace std;

int dp[21][21][21];
int commands[21];
int N,a,b,t,temp;

int solve(int d1, int d2, int idx) {
	if (idx > t) return 0;
	if (dp[d1][d2][idx] != -1) return dp[d1][d2][idx];
	
	int next = commands[idx];
	return dp[d1][d2][idx] = min(solve(next, d2, idx+1) + abs(next-d1),
						solve(d1, next, idx+1) + abs(next-d2));
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>N>>a>>b>>t;
	
	for (int i=1; i<=t; i++) {
		cin>>temp;
		commands[i] = temp;
	}
	
	memset(dp, -1, sizeof(dp));
	cout << solve(a, b, 1) <<'\n';
				
	return 0;
}
// 바텀업 방식

//int main() {
//    ios::sync_with_stdio(false);
//    cin.tie(0);
//    cout.tie(0);
//    
//    cin >> N >> a >> b >> t;
//    
//    for (int i = 1; i <= t; i++) {
//        cin >> temp;
//        commands[i] = temp;
//    }
//    
//    for (int i = 0; i < 21; ++i) {
//        for (int j = 0; j < 21; ++j) {
//            for (int k = 0; k <= t; ++k) {
//                dp[i][j][k] = INF;
//            }
//        }
//    }
//    
//    dp[a][b][0] = 0;
//    
//    for (int idx = 1; idx <= t; ++idx) {
//        int next = commands[idx];
//        for (int d1 = 1; d1 <= N; ++d1) {
//            for (int d2 = 1; d2 <= N; ++d2) {
//                dp[next][d2][idx] = min(dp[next][d2][idx], dp[d1][d2][idx-1] + abs(next - d1));
//                dp[d1][next][idx] = min(dp[d1][next][idx], dp[d1][d2][idx-1] + abs(next - d2));
//            }
//        }
//    }
//    
//    int result = INF;
//    for (int d1 = 1; d1 <= N; ++d1) {
//        for (int d2 = 1; d2 <= N; ++d2) {
//            result = min(result, dp[d1][d2][t]);
//        }
//    }
//    
//    cout << result << '\n';
//    
//    return 0;
//}