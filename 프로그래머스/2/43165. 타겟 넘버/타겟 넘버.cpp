#include <string>
#include <vector>

using namespace std;

int N, T, ans;
vector<int> v;

void check(int res) {
    if (res == T) ans++;
}

void DFS(int idx, int res){
    if (idx == N) {
        check(res);
        return;
    }
    
    DFS(idx + 1, res + v[idx]);
    DFS(idx + 1, res - v[idx]);
}

int solution(vector<int> numbers, int target) {
    ans = 0;
    N = numbers.size();
    T = target;
    v = numbers;
    
    DFS(0, 0);
    
    return ans;
}