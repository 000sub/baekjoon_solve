#include <string>
#include <vector>

using namespace std;

int N;
int rates[4] = {10, 20, 30, 40};
int discount[7];
int amount[101];
int max_cnt = 0, max_val = 0;

vector<vector<int>> glob_users;
vector<int> glob_em;

void check(vector<int>& v){
    int total_cnt = 0, total_val = 0;
    for (auto& p : glob_users){
        int cur_val = 0;
        for (int i=0; i<N; i++){
            if (v[i] >= p[0]) {
                cur_val += glob_em[i] * (100 - v[i]) / 100;
            }
        }
        
        if (cur_val >= p[1]) total_cnt++;
        else total_val += cur_val;
    }
    
    if (max_cnt < total_cnt || (max_cnt == total_cnt && max_val < total_val)) {
        max_cnt = total_cnt;
        max_val = total_val;
    }
}

void search(vector<int> v){
    if (N == v.size()) {
        check(v);
        return;
    }
    
    for (int i=0; i<4; i++){
        v.emplace_back(rates[i]);
        search(v);
        v.pop_back();
    }
}

vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    vector<int> answer;
    
    N = emoticons.size();
    glob_users = users;
    glob_em = emoticons;
    
    vector<int> tmp;
    search(tmp);
    
    answer.emplace_back(max_cnt);
    answer.emplace_back(max_val);
    
    return answer;
}