#include <string>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    stack<int> S1, S2;
    
    int N = numbers.size();
    for (int num : numbers) S1.push(num);
    
    S2.push(S1.top());
    S1.pop();
    answer.push_back(-1);
    
    while (!S1.empty()) {
        int temp = S1.top();
        
        while (!S2.empty() && temp >= S2.top()) S2.pop();
        
        if (S2.empty()) answer.push_back(-1);
        else answer.push_back(S2.top());
        
        S2.push(temp);
        S1.pop();
    }
    
    reverse(answer.begin(), answer.end());
    
    return answer;
}