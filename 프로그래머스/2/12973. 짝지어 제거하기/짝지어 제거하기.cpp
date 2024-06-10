#include <iostream>
#include <string>
#include <stack>
using namespace std;

int solution(string s)
{
    stack<char> st;
    
    for (char c : s) {
        if (st.empty()) {
            st.push(c);
        }
        else if (st.top() == c) {
            st.pop();
        }
        else {
            st.push(c);
        }
    }
    
    return (st.empty()) ? 1 : 0;
}