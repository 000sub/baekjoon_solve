#include <string>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;
const int INF = 10000;

vector<int> solution(vector<string> keymap, vector<string> targets) {
    vector<int> answer;
    int arr[26];
    fill(arr, arr+26, INF);
    
    for (string& s : keymap){
        for (int i=0; i<s.size(); i++) {
            arr[s[i] - 'A'] = min(arr[s[i] - 'A'], i+1);
        }
    }
    
    for (string& s : targets){
        int cnt = 0;
        for (int i=0; i<s.size(); i++){
            if (arr[s[i] - 'A'] == INF) {
                cnt = -1;
                break;
            }
            
            cnt += arr[s[i] - 'A'];
        }
        
        answer.emplace_back(cnt);
    }
    return answer;
}