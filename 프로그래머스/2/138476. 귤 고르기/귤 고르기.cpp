#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;


int solution(int k, vector<int> tangerine) {
    int answer = 0;
    
    unordered_map<int, int> counter;
    vector<int> vals;
    
    for (int t : tangerine) counter[t]++;
    for (auto& entry : counter) vals.push_back(entry.second);
    sort(vals.begin(), vals.end());
    for (int i=vals.size()-1; i>=0; i--) {
        k-=vals[i]; answer++;
        if (k<=0) break;
    }
    
    
    return answer;
}