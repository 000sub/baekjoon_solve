#include <string>
#include <vector>
#include <queue>
using namespace std;

priority_queue<int, vector<int>, greater<int>> pq[6];
vector<vector<int>> mentors_list;
int N;

int solve(vector<int>& mentors, vector<vector<int>>& reqs){
    int res = 0;
    for (int i=1; i<mentors.size(); i++) pq[i] = priority_queue<int, vector<int>, greater<int>>();
    
    for (int i=1; i<mentors.size(); i++)
        for (int j=0; j<mentors[i]; j++) 
            pq[i].push(0);
    
    for (auto req : reqs) {
        int picked = pq[req[2]].top();
        pq[req[2]].pop();
        
        if (picked > req[0]) {
            res += picked - req[0];
            pq[req[2]].push(picked + req[1]);
        }
        else {
            pq[req[2]].push(req[0] + req[1]);
        }
        
    }
    
    return res;
}

void choose(int len, int type, vector<int> mentors){
    if (len == N) {
        mentors_list.push_back(mentors);
        return;
    }
    
    for (int i=type; i<mentors.size(); i++) {
        mentors[i]++;
        choose(len+1, i, mentors);
        mentors[i]--;
    }
}



int solution(int k, int n, vector<vector<int>> reqs) {
    int answer = 1e9;
    N = n;
    
    
    vector<int> temp(k+1, 1);
    choose(k,1,temp);
    
    for (auto& mentors : mentors_list) {
        int res = solve(mentors, reqs);
        answer = min(answer, res);
    }
    
    return answer;
}