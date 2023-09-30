#include <string>
#include <vector>
#include <iostream>
#include <stack>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    
    stack<char> s;
    
    for (int i=0; i<number.size(); i++){
        while (!s.empty() && number[i] > s.top() && k>0) {s.pop(); k--;}
        s.push(number[i]);
    }
    
    while (k--) s.pop();
    while (!s.empty()){
        answer = s.top() + answer;
        s.pop();
    }
    
    
    return answer;
    
    
}