#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

unordered_map<string, int> cache;

void del(){
    string tmp = "";
    int minT = 1e9;
    for (auto& iter : cache) {
        if (minT > iter.second) {
            tmp = iter.first;
            minT = iter.second;
        }
    }
    
    cache.erase(tmp);
}

int solution(int cacheSize, vector<string> cities) {
    int answer;
    int t = 0;
    
    if (cacheSize == 0) {
        return cities.size() * 5;
    }
    for (string s : cities) {
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        if (cache.count(s)) {
            t+=1;
            cache[s] = t;
        }
        else {
            t+=5;
            if (cache.size() == cacheSize) del();
            cache[s] = t;
        }
    }
    
    answer = t;
    return answer;
}