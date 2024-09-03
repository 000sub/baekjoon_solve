#include <string>
#include <vector>
#include <queue>

using namespace std;
typedef long long ll;

typedef struct Node {
    ll visited;
    int cnt;
    string str;
} Node;

bool canMove(string& a, string& b) {
    bool used = false;
    for (int i=0; i<a.size(); i++) {
        if (a[i] != b[i]) {
            if (used) return false;
            else used = true;
        }
    }
    return true;
}


int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    
    queue<Node> q;
    q.push({0LL, 0, begin});
    while (!q.empty()) {
        ll visited = q.front().visited;
        int cnt = q.front().cnt;
        string str = q.front().str;
        q.pop();
        
        if (str == target) {
            return cnt;
        }
        
        for (int i=0; i<words.size(); i++) {
            if (canMove(str, words[i]) && !(visited & (1LL<<i))) {
                q.push({visited | (1LL<<i), cnt+1, words[i]});
            }
        }
    }
    return 0;
}