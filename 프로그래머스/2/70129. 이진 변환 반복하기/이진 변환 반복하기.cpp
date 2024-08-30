#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    
    int zeroCnt = 0, opCnt = 0;
    
    while (s != "1") {
        int N = 0;
        for (char c : s) if (c=='0') zeroCnt++; else N++;
        s.clear();
        
        while (N) {
            s += (N & 1) ? "1" : "0";
            N>>=1;
        }
        reverse(s.begin(), s.end());
        opCnt++;
    }
    
    answer.push_back(opCnt);
    answer.push_back(zeroCnt);
    
    
    return answer;
}