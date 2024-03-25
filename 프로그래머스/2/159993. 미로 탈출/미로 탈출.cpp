#include <string>
#include <vector>
#include <cstring>
#include <queue>
#define PII pair<int,int>

using namespace std;

int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1,0,0};
int N,M;
const int INF = 1e9;

int BFS(PII start, PII goal, vector<string>& maps) {
    int min_cnt = INF;
    bool visited[N][M];
    memset(visited, 0, sizeof(visited));
    
    queue<pair<int, PII>> q;
    q.push(make_pair(0, start));
    
    while (!q.empty()) {
        int cur_cnt = q.front().first;
        int curx = q.front().second.first;
        int cury = q.front().second.second;
        q.pop();
                
        if (curx == goal.first && cury == goal.second)
            return cur_cnt;
        
        for (int i=0;i<4;i++) {
            int nx = curx+dx[i];
            int ny = cury+dy[i];
            
            if (nx >= N || ny >= M || nx < 0 || ny < 0 || maps[nx][ny] == 'X') 
                continue;
            if (!visited[nx][ny] && cur_cnt + 1 < min_cnt) {
                visited[nx][ny] = true;
                q.push(make_pair(cur_cnt+1, PII(nx, ny)));
            }
                
        }  
    }
    
    return min_cnt;
    
}

int solution(vector<string> maps) {
    PII start, exit, lever;
    N = maps.size();
    M = maps[0].size();
    
    for (int i=0;i<N;i++) {
        for (int j=0;j<M;j++) {
            if (maps[i][j] == 'S') start = PII(i, j);
            else if (maps[i][j] == 'E') exit = PII(i,j);
            else if (maps[i][j] == 'L') lever = PII(i,j);
        }
    }
    
    int answer = BFS(start, lever, maps) + BFS(lever, exit, maps);
    return (answer >= INF) ? -1 : answer;
}