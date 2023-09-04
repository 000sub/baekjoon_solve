#include <string>
#include <vector>
#include <cmath>
using namespace std;

long long solution(int k, int d) {
    long long answer = 0;
    
    for (int i=0; i<=d; i+=k){
        long long cnt = floor(sqrt((long long)d*d-(long long)i*i)/k)+1;
        answer+=cnt;
    }
    return answer;
}