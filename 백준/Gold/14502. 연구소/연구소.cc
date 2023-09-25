#include <iostream>
#include <string>
#include <algorithm>

#define PII pair<int, int>

using namespace std;
int N, M;
int map[9][9];
int tmp[9][9];
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
int ans = 0;

void dfs(int x, int y){
    for (int d=0; d<4; d++){
        int nx = x + dx[d];
        int ny = y + dy[d];
        
        if (nx<0||ny<0||nx>N-1||ny>M-1) continue;
        
        if (tmp[nx][ny] == 0) {
            tmp[nx][ny] = 2;
            dfs(nx, ny);
        }
    }
}
void search(){
    
    for (int i=0; i<N; i++)
        for (int j=0; j<M; j++)
            tmp[i][j] = map[i][j];
        
    for (int i=0; i<N; i++){
        for (int j=0; j<M; j++){
            if (tmp[i][j] == 2) dfs(i,j);
        }
    }
    
    int cnt = 0;
    
    for (int i=0; i<N; i++)
        for (int j=0; j<M; j++)
            if (tmp[i][j] == 0) cnt++;
    
    ans = max(ans, cnt);
}

void build_wall(int cnt){
    if (cnt == 3) {
        search();
        return;
    }
    
    for (int i=0; i<N; i++){
        for (int j=0; j<M; j++){
            if (map[i][j] == 0){
                map[i][j] = 1;
                build_wall(cnt+1);
                map[i][j] = 0;
            }
        }
    }
}
int main(int argc, char** argv)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin>>N>>M;
    
    for (int i=0; i<N; i++){
        for (int j=0; j<M; j++){
            cin>>map[i][j];
        }
    }
    
    
    build_wall(0);
    cout<<ans<<'\n';
    return 0;
}
