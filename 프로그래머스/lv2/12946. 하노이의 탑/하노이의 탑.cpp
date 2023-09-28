#include <string>
#include <vector>

using namespace std;

void move(vector<vector<int>>& v, int s, int e, int n){
    
    if (n==1) {
        vector<int> tmp = {s,e};
        v.push_back(tmp);
        return;
    }
    
    move(v, s, s^e , n-1);
    vector<int> tmp = {s,e};
    v.push_back(tmp);
    move(v, s^e, e, n-1);
}

vector<vector<int>> solution(int n) {
    vector<vector<int>> answer;
    
    move(answer, 1, 3, n);

    return answer;
}