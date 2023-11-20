#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    int answer = -1;
    
    
    int len = queue1.size();
    queue<int> q1, q2;
    
    long long sum1 = 0, sum2 = 0;
    for (auto i : queue1) {
        sum1 += i;
        q1.push(i);
    }
    for (auto i : queue2) {
        sum2 += i;
        q2.push(i);
    }
    
    int cnt;
    for (cnt = 0; cnt < len * 4; cnt++) {
        if (sum1 == sum2) break;
        else if (sum1 > sum2) {
            sum1 -= q1.front();
            sum2 += q1.front();
            q2.push(q1.front());
            q1.pop();
        }
        else {
            sum2 -= q2.front();
            sum1 += q2.front();
            q1.push(q2.front());
            q2.pop();
        }
    }
    
    if (cnt != len*4) answer = cnt;
    return answer;
}