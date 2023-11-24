#include <string>
#include <vector>
#include <iostream>
using namespace std;

int dp[301][301];
int solution(int alp, int cop, vector<vector<int>> problems) {
    int answer = 1e9;
    int tgt_alp=0, tgt_cop=0;
    
    for (auto problem : problems){
        tgt_alp = max(tgt_alp, problem[0]);
        tgt_cop = max(tgt_cop, problem[1]);
    }
    
    if (tgt_alp <= alp && tgt_cop <= cop) return 0;
    if (tgt_alp < alp) alp = tgt_alp;
    if (tgt_cop < cop) cop = tgt_cop;
    
    for (int i=0; i<=300; i++) for (int j=0; j<=300; j++) dp[i][j] = 1e9;
    dp[alp][cop] = 0;
    
    for (int i=alp; i<=tgt_alp; i++){
        for (int j=cop;j<=tgt_cop; j++){
            dp[i+1][j] = min(dp[i+1][j], dp[i][j] + 1);
            dp[i][j+1] = min(dp[i][j+1], dp[i][j] + 1);
            for (auto problem : problems){
                if (i >= problem[0] && j >= problem[1]) {
                    dp[min(i+problem[2], tgt_alp)][min(j+problem[3], tgt_cop)] = 
                        min(dp[min(i+problem[2], tgt_alp)][min(j+problem[3], tgt_cop)], dp[i][j] + problem[4]);
                }  
            }
        }
    }
    
    answer = dp[tgt_alp][tgt_cop];
    
    return answer;
}