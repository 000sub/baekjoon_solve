#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Node {
    int s;
    int e;
    int cost;
    
    bool operator<(Node& other) {
        return cost < other.cost;
    }
};

int parent[101];
vector<Node> v;

int Find(int x) {
    if (parent[x] == x) return x;
    return parent[x] = Find(parent[x]);
}

void Union(int a, int b) {
    a = Find(a);
    b = Find(b);
    if (a<b) parent[b] = a;
    else parent[a] = b;
}


int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    for (int i=0; i<n; i++) parent[i] = i;
    
    for (auto& cost : costs) {
        v.push_back({cost[0], cost[1], cost[2]});
    }
    
    sort(v.begin(), v.end());
    
    for (int i=0; i<v.size(); i++) {
        int s = v[i].s;
        int e = v[i].e;
        int cost = v[i].cost;
        
        if (Find(s) != Find(e)) {
            answer += cost;
            Union(s, e);
        }
    }
    
    return answer;
}