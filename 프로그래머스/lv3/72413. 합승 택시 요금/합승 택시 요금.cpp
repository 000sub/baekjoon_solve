#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#define PII pair<int, int>

using namespace std;
const int INF = 1e9;
int dist[201];
vector<PII> graph[201];

void dijkstra(int k){
    priority_queue<PII, vector<PII>, greater<PII>> pq;
    fill(dist, dist+201, INF);
    dist[k] = 0;
    pq.push(PII(0, k));
    
    while (!pq.empty()){
        int curcost = pq.top().first;
        int curpos = pq.top().second;
        pq.pop();
        
        if (curcost > dist[curpos]) continue;
        
        for (auto& p : graph[curpos]){
            if (p.second + curcost < dist[p.first]){
                dist[p.first] = p.second + curcost;
                pq.push(PII(dist[p.first], p.first));
            }
        }
    }
    
}
int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = 0;
    
    for (vector<int>& v : fares){
        graph[v[0]].emplace_back(v[1], v[2]);
        graph[v[1]].emplace_back(v[0], v[2]);
    }
    
    dijkstra(s);
    answer = INF;
    for (int i=1; i<=n; i++){
        dijkstra(i);
        if (dist[a]==INF || dist[b]==INF || dist[s]==INF) continue;
        answer = min(answer, dist[a] + dist[b] + dist[s]);
    }
    
    return answer;
}