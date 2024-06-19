#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    
    priority_queue<int, vector<int>, greater<int>> pq;
    
    for (int i : scoville) pq.push(i);
    
    while (pq.top() < K) {
        int a = pq.top();
        pq.pop();
        
        if (pq.empty()) return -1;
        
        int b = pq.top();
        pq.pop();
        
        pq.push(a+b*2);
        answer++;
    }
    
    
    return answer;
}