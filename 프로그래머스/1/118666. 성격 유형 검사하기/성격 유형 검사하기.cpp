#include <string>
#include <vector>
#include <unordered_map>
using namespace std;


string solution(vector<string> survey, vector<int> choices) {
    char types[8] = {'R','T', 'C', 'F', 'J', 'M', 'A', 'N'};
    unordered_map<char, int> m;
    string answer = "";
    
    for (int i=0; i<survey.size(); i++) {
        string s = survey[i];
        int choice = choices[i];
        
        if (choice == 4) continue;
        else if (choice > 4) m[s[1]] += choice - 4;
        else m[s[0]] += 4 - choice;
    }
    
    for (int i=0; i<8; i+=2){
        answer +=  m[types[i]] < m[types[i+1]] ? types[i+1] : types[i];
    }
    
    
    return answer;
}