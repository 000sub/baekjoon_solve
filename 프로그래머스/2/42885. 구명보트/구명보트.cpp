#include <string>
#include <vector>
#include <algorithm>
#include <deque>
using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    deque<int> dq;
    int boat = limit;
    
    sort(people.begin(), people.end());
    
    for (int i: people) dq.push_back(i);
    
    while (dq.size() > 1) {
        int minP = dq.front();
        int maxP = dq.back();
        dq.pop_front(); dq.pop_back();
        
        while (!dq.empty() && minP + maxP > limit) {
            answer++;
            maxP = dq.back();
            dq.pop_back();
        }
        
        if (minP + maxP > limit) answer+=2;
        else answer++;
    }
    
    if (!dq.empty()) answer++;
    
    return answer;
}