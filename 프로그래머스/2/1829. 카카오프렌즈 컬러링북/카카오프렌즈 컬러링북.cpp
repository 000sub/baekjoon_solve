#include <vector>
#include <queue>
#include <algorithm>
#define PII pair<int, int>
using namespace std;


bool visited[101][101];
int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1,0,0};
int M, N;
vector<vector<int>> map;
// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.

int BFS(PII pos){
    queue<PII> q;
    int cnt = 0;
    int elem = map[pos.first][pos.second];
    q.push(pos);
    visited[pos.first][pos.second] = true;
    
    while (!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        cnt++;
        
        for (int i=0; i<4; i++){
            int nx = x+dx[i];
            int ny = y+dy[i];
            
            if (nx<0||ny<0||nx>M-1||ny>N-1) continue;
            
            if (map[nx][ny] == elem && !visited[nx][ny]){
                visited[nx][ny] = true;
                q.push(PII(nx,ny));
            }
        }
    }
    
    return cnt;
}
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    
    M = m;
    N = n;
    map = picture;
    for (int i=0; i<101; i++) for (int j=0; j<101; j++) visited[i][j] = false;
    
    for (int i=0; i<m; i++){
        for (int j=0; j<n; j++){
            if (!visited[i][j] && map[i][j] > 0) {
                int res = BFS(PII(i,j));
                max_size_of_one_area = max(max_size_of_one_area, res);
                number_of_area++;
            }
        }
    }
    
    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}