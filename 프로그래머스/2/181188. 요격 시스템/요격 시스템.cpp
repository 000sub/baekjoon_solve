#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(vector<int>& a, vector<int>& b){
    return a[1] < b[1];
}

int solution(vector<vector<int>> targets) {
    int answer = 0;
    
    sort(targets.begin(), targets.end(), cmp);
    
    //end값이 갱신 = 요격 발생
    int end = 0;
    for (vector<int>& v: targets) {
        if (v[0] >= end) {
            answer++;
            end = v[1];
        }
    }
    return answer;
}