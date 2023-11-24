#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#define PII pair<int, int>
using namespace std;

vector<vector<PII>> graph;
bool is_summit[50001];
int intensity[50001];

PII dijkstra(vector<int>& gates){
    priority_queue<PII, vector<PII>, greater<PII>> pq;
    vector<PII> res;
    for (auto gate : gates){
        pq.push(PII(0, gate));
    }
    
    while (!pq.empty()) {
        int cur_pos = pq.top().second;
        int cur_cost = pq.top().first;
        pq.pop();
        
        if (intensity[cur_pos] < cur_cost) continue;
                
        if (is_summit[cur_pos]) {
            res.emplace_back(cur_cost, cur_pos);
            continue;
        }
        
        for (auto p : graph[cur_pos]){
            if (intensity[p.second] == 0 || max(cur_cost, p.first) < intensity[p.second]){
                intensity[p.second] = max(cur_cost, p.first);
                pq.push(PII(intensity[p.second], p.second));
            }
        }
    }
    
    sort(res.begin(), res.end());
    return res[0];
    
    
}
vector<int> solution(int n, vector<vector<int>> paths, vector<int> gates, vector<int> summits) {
    vector<int> answer;
    graph.resize(n+1);
    
    for (auto path : paths) {
        graph[path[0]].push_back(PII(path[2], path[1]));
        graph[path[1]].push_back(PII(path[2], path[0]));
    }
    
    for (auto summit : summits){
        is_summit[summit] = true;
    }
    
    PII p = dijkstra(gates);
    answer.push_back(p.second);
    answer.push_back(p.first);
    
    return answer;
}