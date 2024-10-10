#include <string>
#include <vector>

using namespace std;

int ans = 1e9;
int N;
int info[3][3] = {{1,1,1}, {5,1,1}, {25,5,1}};
vector<string> v;
int calcTime(int type, int idx) {
    int cnt = 0;
    for (int i=0; i<5; i++) {
        if (idx + i >= v.size()) break;
        string& cur = v[idx+i];
        if (cur == "diamond") {
            cnt += info[type][0];
        }
        else if (cur == "iron") {
            cnt += info[type][1];
        }
        else {
            cnt += info[type][2];
        }
    }
    return cnt;
}

void dfs(int dCnt, int iCnt, int sCnt, int idx, int t) {
    if (idx >= N || (dCnt==0 && iCnt==0 && sCnt==0)) {
        ans = min(ans, t);
        return;
    }
    
    if (dCnt > 0) {
        dfs(dCnt-1, iCnt, sCnt, idx+5, t + calcTime(0, idx));
    }
    if (iCnt > 0) {
        dfs(dCnt, iCnt-1, sCnt, idx+5, t + calcTime(1, idx));
    }
    if (sCnt > 0) {
        dfs(dCnt, iCnt, sCnt-1, idx+5, t + calcTime(2, idx));
    }
}

int solution(vector<int> picks, vector<string> minerals) {
    N = minerals.size();
    v = minerals;
    dfs(picks[0], picks[1], picks[2], 0, 0);
    return ans;
}