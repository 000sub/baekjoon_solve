#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

vector<string> parse(string s){
    vector<string> res;
    string tmp = "";
    
    for (char c: s){
        if (c == ' '){
            if (tmp != "and") res.push_back(tmp);
            tmp = "";
        }
        else tmp += c;
    }
    res.push_back(tmp);
    return res;
}

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;
    unordered_map<string, vector<int>> m;
    for (string s : info) {
        vector<string> key = parse(s);
        for (int i=0; i<16; i++){
            string tmp = "";
            for (int j=0; j<4; j++){
                tmp += (i & (1<<j)) ? key[j] : "-";
            }
            m[tmp].push_back(stoi(key[4]));
        }
    }
    
    for (auto& iter : m) {
        sort(iter.second.begin(), iter.second.end());
    }
    
    for (string q : query){
        vector<string> key = parse(q);
        string k = key[0] + key[1] + key[2] + key[3];
        vector<int>& v = m[k];
        
        int cnt = v.end() - lower_bound(v.begin(), v.end(), stoi(key[4]));
        answer.push_back(cnt);
    }
    
    
    return answer;
}