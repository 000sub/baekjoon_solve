#include <string>
#include <vector>

using namespace std;

int check(int k) {
    int res = 0;
    for (;k>0;k>>=1) {
        if (k%2) res++;
    }
        
    return res;
}

int solution(int n) {
    int answer = n+1;
    int N = check(n);
    
    while (1) {
        if (check(answer) == N) return answer;
        answer++;
    }
    return -1;
}