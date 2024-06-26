#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int solution(string s) {
    int answer = 0;
    answer = s.size();
    
    for (int i=1; i<=s.size()/2; i++) {
        string cur = s.substr(0, i);
        int newLen = 0;
        int compCnt= 0;
        for (int j=i; j<s.size(); j+=i) {
            
            //남은 문자열이 i 크기보다 작음
            if (s.size() - j < i) {
                newLen += s.size() - j;
                break;
            }
            
            string temp = s.substr(j, i);
            if (temp == cur) {
                compCnt++;
                continue;
            }
            
            //일치하지 않다면 압축 문자열의 길이를 newLen에 더한다.
            //((int)log10(compCnt+1) + 1) : 압축 횟수의 숫자 길이
            newLen += compCnt ? i + ((int)log10(compCnt+1) + 1) : i;
            compCnt = 0;
            cur = temp;
        }
        
        newLen += compCnt ? i + ((int)log10(compCnt+1) + 1) : i;
        
        answer = min(answer, newLen);
    }
    
    return answer;
}