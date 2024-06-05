#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int dp[501][501];

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    
    int h = triangle.size();
    
    dp[0][0] = triangle[0][0];
    dp[1][0] = dp[0][0] + triangle[1][0];
    dp[1][1] = dp[0][0] + triangle[1][1];
    
    for (int i=2; i<h; i++) {
        for (int j=0; j<=i; j++) {
            if (j==0) dp[i][j] = dp[i-1][j] + triangle[i][j];    
            else if (j == i) dp[i][j] = dp[i-1][j-1] + triangle[i][j];
            else dp[i][j] = max(dp[i-1][j-1], dp[i-1][j]) + triangle[i][j];
        }
    }
    
    for (int i=0; i<h; i++) answer = max(answer, dp[h-1][i]);
    
    return answer;
}