#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <stack>

#define PII pair<int,int>

using namespace std;
typedef long long ll;

int R, C, ans = 0;
char ch;
bool visited[10001][501];

bool dfs(int x, int y) {
    if (y == C-1) {
        ans++;
        return true;
    }

    if (x-1 >= 0 && !visited[x-1][y+1]) {
        visited[x-1][y+1] = true;
        if (dfs(x-1, y+1)) return true;
    }

    if (!visited[x][y+1]) {
        visited[x][y+1] = true;
        if (dfs(x, y+1)) return true;
    }

    if (x+1 < R && !visited[x+1][y+1]) {
        visited[x+1][y+1] = true;
        if (dfs(x+1, y+1)) return true;
    }

    return false;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>R>>C;
    for (int i=0; i<R; i++) {
        for (int j=0; j<C; j++) {
            cin>>ch;
            if (ch == 'x') visited[i][j] = true;
        }
    }
    
    for (int i=0; i<R; i++) {
        dfs(i, 0);
    }

    cout << ans;
    return 0;
}