#include <string>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

typedef struct data {
    string name;
    int start_time;
    int process_time;
} Data;

bool compare(Data& a, Data& b){
    return a.start_time < b.start_time;
}

vector<string> solution(vector<vector<string>> plans) {
    vector<string> answer;
    vector<Data> v;
    stack<Data> s;
    
    for (int i=0; i<plans.size(); i++){
        Data temp;
        temp.name = plans[i][0];
        temp.start_time = plans[i][1][0] * 600 + plans[i][1][1] * 60 +
            plans[i][1][3] * 10 + plans[i][1][4];
        temp.process_time = stoi(plans[i][2]);
        
        v.push_back(temp);
    }
    
    sort(v.begin(), v.end(), compare);
    
    int cur_time = v[0].start_time;
    Data cur = v[0];
    int i=1;
    while (i < v.size()) {
        if (v[i].start_time < cur.process_time + cur_time) {
            cur.process_time -= v[i].start_time - cur_time;
            s.push(cur);
            cur = v[i];
            cur_time = v[i].start_time;
            i++;
        } else {
            if (s.empty()){
                answer.push_back(cur.name);
                cur = v[i];
                cur_time = v[i].start_time;
                i++;
            } else {
                answer.push_back(cur.name);
                cur_time += cur.process_time;
                cur = s.top();
                s.pop();
            }
            
        }
    }
    
    answer.push_back(cur.name);
        
    while (!s.empty()) {
        answer.push_back(s.top().name);
        s.pop();
    }
    return answer;
}