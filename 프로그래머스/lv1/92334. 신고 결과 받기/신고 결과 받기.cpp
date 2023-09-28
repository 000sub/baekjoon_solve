#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <unordered_set>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;
    unordered_map<string, unordered_set<string>> user_map;
    unordered_map<string, int> cnt_map;
    
    for (int i=0; i<report.size(); i++){
        string s = report[i];
        string src = s.substr(0, s.find(' '));
        string dst = s.substr(s.find(' ')+1);
        
        int tmp = user_map[src].size();
        user_map[src].insert(dst);
        if (user_map[src].size() != tmp) cnt_map[dst]++;
    }
    
    for (int i=0; i<id_list.size(); i++){
        string s = id_list[i];
        int cnt = 0;
        for (auto& el : user_map[s]) {
            if (cnt_map[el] >= k) cnt++;
        }
        
        answer.emplace_back(cnt);
    }
    return answer;
}