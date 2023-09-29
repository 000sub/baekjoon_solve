#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    
    int lo = 1, hi = 1, sum = 1;
    
    while (1){
        if (lo > n || hi > n) break;
        
        if (sum > n) {
            sum -= lo++;
        }
        else if (sum < n) {
            sum += ++hi;
        }
        else {
            answer++;
            sum += ++hi;
        }
    }

    return answer;
}