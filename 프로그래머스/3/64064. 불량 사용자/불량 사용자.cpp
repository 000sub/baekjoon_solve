#include <string>
#include <vector>
#include <set>

using namespace std;

vector<vector<int>> map;
set<set<int>> ans;

bool check(string& s1, string& s2) {
    if (s1.length() != s2.length()) return false;
    
    for (int i=0; i<s1.length(); i++) {
        if (s2[i] != '*' && s1[i] != s2[i]) return false;
    }
    
    return true;
}

void build(vector<string>& user_id, vector<string>& banned_id) {
    for (int i=0; i<banned_id.size(); i++) {
        vector<int> v;
        for (int j=0; j<user_id.size(); j++) {
            if (check(user_id[j], banned_id[i])) v.push_back(j);
        }
        map.push_back(v);
    }
}

void BT(set<int> s, int size) {
    if (s.size() == size) {
        ans.insert(s);
        return;
    }
    
    for (int i : map[s.size()]) {
        int tempSize = s.size();
        s.insert(i);
        if (s.size() > tempSize) {
            BT(s, size);
            s.erase(i);
        }
    }
}

int solution(vector<string> user_id, vector<string> banned_id) {
    
    build(user_id, banned_id);
    
    set<int> s;
    BT(s, banned_id.size());
    
    
    return ans.size();
}