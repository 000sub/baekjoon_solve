#include <string>
#include <vector>

using namespace std;

int fibo[100001];
const int MOD = 1234567;
int solution(int n) {
    int answer = 0;
    
    fibo[0] = 0;
    fibo[1] = 1, fibo[2] = 1;
    
    for (int i=2; i<=n; i++){
        fibo[i] = (fibo[i-1] + fibo[i-2]) % MOD;
    }
     
    answer = fibo[n];
    return answer;
}