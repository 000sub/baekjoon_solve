#include <string>
#include <vector>
#include <queue>
#define PII pair<int,int>
using namespace std;

bool visited[1000001];

int BFS(int x, int y, int n) {
    priority_queue<PII, vector<PII>, greater<PII>> pq;
    
    pq.push(PII(0, x));
    
    while (!pq.empty()){
        int cur_cnt = pq.top().first;
        int cur_val = pq.top().second;
        pq.pop();
        
        if (cur_val == y) return cur_cnt;
        
        if (!visited[cur_val * 2] && cur_val * 2 <= y) {
            pq.push(PII(cur_cnt+1, cur_val*2));
            visited[cur_val * 2] = true;
        }
        if (!visited[cur_val * 3] && cur_val * 3 <= y) {
            pq.push(PII(cur_cnt+1, cur_val*3));
            visited[cur_val * 3] = true;
        }
        if (!visited[cur_val + n] && cur_val + n <= y) {
            pq.push(PII(cur_cnt+1, cur_val+n));
            visited[cur_val + n] = true;
        }
    }
    
    return -1;
}

int solution(int x, int y, int n) {
    int answer = BFS(x,y,n);
    return answer;
}