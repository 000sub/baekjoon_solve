#include <string>
#include <vector>

using namespace std;

vector<vector<int>> v;
bool visited[201];
int answer = 0;
int N;

void DFS(int k) {
    visited[k] = true;
    
    for (int i=0; i<N; i++) {
        if (v[k][i] && !visited[i]) DFS(i);
    }
}

int solution(int n, vector<vector<int>> computers) {
    v = computers;
    N = n;
    
    for (int i=0; i<n; i++) {
        if (!visited[i]) {answer++; DFS(i);}
    }
    
    return answer;
}