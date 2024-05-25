#include <string>
#include <vector>
#include <set>
#include <sstream>
using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    multiset<int> ms;
    char op;
    int num;
    
    for (string s : operations) {
        istringstream iss(s);
        iss >> op >> num;
        
        if (op == 'I') {
            ms.insert(num);
        }
        else {
            if (ms.empty()) continue;
            
            if (num == -1) {
                ms.erase(ms.begin());
            }
            else {
                ms.erase(--ms.end());
            }
        }
    }
    
    if (ms.empty()) {
        answer.push_back(0);
        answer.push_back(0);
    }
    else {
        answer.push_back(*(--ms.end()));
        answer.push_back(*ms.begin());
    }
    return answer;
}