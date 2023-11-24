#include <string>
#include <vector>
using namespace std;

int N;
vector<int> INFO, ryan, apeach, answer = {-1};
int maxDiff = 0;

bool cmp(vector<int>& a, vector<int>& b) {
    for (int i=11; i>=0; i--){
        if (a[i] != b[i]) return a[i] > b[i];
    }
    return false;
}

void check() {
    int rRes=0, aRes=0, res;
    
    for (int i=0; i<11; i++){
        if (ryan[i] > apeach[i]) rRes += 10-i;
        else if (ryan[i] < apeach[i]) aRes += 10-i;
        else continue;
    }
    
    if (maxDiff < rRes - aRes) {
        answer = ryan;
        maxDiff = rRes - aRes;
    }
    else if (maxDiff == rRes - aRes) {
        if (answer.size() != 11 || cmp(ryan, answer)) answer = ryan;
    }
}
    
void DFS(int idx, int left){
    if (left == 0 || idx == 10) {
        //return score
        ryan[idx] = left;
        check();
        ryan[idx] = 0;
        return;
    }
    
    if (apeach[idx] + 1 <= left) {
        ryan[idx] = apeach[idx] + 1;
        DFS(idx+1, left - apeach[idx] - 1);
        ryan[idx] = 0;
    }
    

    DFS(idx+1, left);
}

vector<int> solution(int n, vector<int> info) {
    ryan.resize(11);
    apeach = info;
    N=n;
    
    DFS(0, n);
    if (maxDiff == 0) answer = {-1};
    return answer;
}