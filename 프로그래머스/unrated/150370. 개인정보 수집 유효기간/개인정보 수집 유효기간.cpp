#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    unordered_map<char, int> delay;
    
    for (int i=0; i<terms.size(); i++){
        string& s = terms[i];
        char c = s[0];
        delay[c] = stoi(s.substr(2));
    }
    
    int today_val = stoi(today.substr(0,4)) *12*28 + (stoi(today.substr(5,2)) -1)*28 + stoi(today.substr(8,2));
    
    for (int i=0; i<privacies.size(); i++){
        string& s = privacies[i];
        int val = stoi(s.substr(0,4))*12*28 + (stoi(s.substr(5,2))-1)*28 + stoi(s.substr(8,2));
        char c = s[11];
        
        int newval = delay[c] * 28 -1 +val;    
        if (newval < today_val) answer.emplace_back(i+1);
    }
    return answer;
}