#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string s) {
    string answer = "";
    vector<int> v;
    int prev_pos = 0;
    for (int i=0; i<=s.size(); i++){
        if (i == s.size() || s[i] == ' ') {
            int temp = stoi(s.substr(prev_pos, i-prev_pos));
            v.push_back(temp);
            
            if (i+1 < s.size()) prev_pos = i+1;
        }
    }
    sort(v.begin(), v.end());
    answer += to_string(v.front()) + " " + to_string(v.back());
    
    return answer;
}