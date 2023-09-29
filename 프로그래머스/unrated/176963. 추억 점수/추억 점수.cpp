#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photo) {
    unordered_map<string, int> umap;
    vector<int> answer;
    
    for (int i=0; i<name.size(); i++){
        umap[name[i]] = yearning[i];
    }
    
    for (vector<string>& v : photo) {
        int cnt = 0;
        for (string& s : v) {
            cnt += umap[s];
        }
        answer.emplace_back(cnt);
    }
    return answer;
}