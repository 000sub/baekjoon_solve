#include <vector>
#include <queue>
#define PII pair<int,int>
#define PIII pair<int, PII>
using namespace std;

bool visited[101][101];
int dx[] = {0,1,-1,0};
int dy[] = {1,0,0,-1};

int solution(vector<vector<int> > maps)
{
    int n = maps.size();
    int m = maps[0].size();
    
    queue<PIII> q;
    visited[0][0] = true;
    q.push({1, {0,0}});
    while (!q.empty()) {
        int cnt = q.front().first;
        int x = q.front().second.first;
        int y = q.front().second.second;
        q.pop();
        
        if (x == n-1 && y == m-1) {
            return cnt;
        }
        
        for (int d=0; d<4; d++) {
            int nx = x + dx[d];
            int ny = y + dy[d];
            
            if (nx<0||ny<0||nx>=n||ny>=m||visited[nx][ny]||maps[nx][ny]==0) continue;
            
            q.push({cnt+1, {nx, ny}});
            visited[nx][ny] = true;
        }
        
        
    }
    
    
    return -1;
}