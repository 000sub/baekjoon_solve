#include <string>
#include <vector>
#include <algorithm>
#include <queue>

#define PII pair<int,int>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int curT = 0;
    int curW = 0;
    int idx = 0;
        
    queue<int> q;
    
    while (1) {
        if (idx == truck_weights.size()) {
            curT += bridge_length;
            break;
        }
        
        int truck = truck_weights[idx];
        
        if (q.size() == bridge_length) {
            curW -= q.front();
            q.pop();
        }
        
        //최대 무게 - 현재 무게 >= 실을 트럭 무게라면 push
        if (weight - curW >= truck){
            q.push(truck);
            curW += truck;
            idx++;
        } else {
            q.push(0);
        }
        
        curT++;
    }
    
    return curT;
}