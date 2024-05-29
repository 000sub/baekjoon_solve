#include <string>
#include <vector>
#include <map>
using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    map<string, int> m;
    
    for (vector<string> v : clothes) {
        m[v[1]]++;
    }
    
    for (auto it : m) {
        answer *= (it.second+1);
    }
    
    return answer-1;
}