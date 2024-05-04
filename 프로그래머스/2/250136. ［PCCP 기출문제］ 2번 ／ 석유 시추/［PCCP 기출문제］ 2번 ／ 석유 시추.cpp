#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#define PII pair<int, int>
using namespace std;

int oil_idx_size[501];
bool visited[501][501];

vector<vector<int>> oilmap;

int dx[] = {0,0,-1,1};
int dy[] = {1,-1,0,0};
int n,m, oil_idx = 1;

void BFS(int x, int y) {
    int cnt = 0;
    queue<PII> q;
    
    q.push({x,y});
    oilmap[x][y] = oil_idx;
    visited[x][y] = true;
    
    while(!q.empty()) {
        int _x = q.front().first;
        int _y = q.front().second;
        cnt++;
        q.pop();
        
        for (int d=0; d<4; d++) {
            int nx = _x + dx[d];
            int ny = _y + dy[d];
            
            if (nx<0||ny<0||nx>n-1||ny>m-1||visited[nx][ny]) continue;
            if (!oilmap[nx][ny]) continue;
            
            oilmap[nx][ny] = oil_idx;
            visited[nx][ny] = true; 
            q.push({nx, ny});
        }
    }
    
    oil_idx_size[oil_idx++] = cnt;
}
int solution(vector<vector<int>> land) {
    int answer = 0;
    n = land.size();
    m = land[0].size();
    oilmap = land;
    
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (!visited[i][j] && land[i][j]) BFS(i, j);
        }
    }
    
    for (int j=0; j<m; j++) {
        set<int> s;
        int ans = 0;
        
        for (int i=0; i<n; i++) {
            s.emplace(oilmap[i][j]);
        }
        
        for (int idx : s) {
            ans += oil_idx_size[idx];
        }
        
        answer = max(answer, ans);
    }
    
    
    return answer;
}