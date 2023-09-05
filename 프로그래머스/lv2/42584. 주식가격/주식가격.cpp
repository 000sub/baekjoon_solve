#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    int n = prices.size();
    answer.resize(n);
    
    stack<int> s;
    
    for (int i=0; i<n; i++){
        if (s.empty()){
            s.push(i);
            continue;
        }
        
        int last_t = s.top();
        if (prices[last_t] <= prices[i]) s.push(i);
        else {
            while (!s.empty() && prices[s.top()] > prices[i]){
                answer[s.top()] = i - s.top();
                s.pop();
            }
            s.push(i);
        }
    }
    
    while (!s.empty()){
        answer[s.top()] = n-1 - s.top();
        s.pop();
    }
    return answer;
}