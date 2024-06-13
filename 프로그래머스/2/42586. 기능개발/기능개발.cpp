#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    
    int N = progresses.size();
    int curT = 0;
    
    for (int i=0; i<N;) {
        curT = (100 - progresses[i]) / speeds[i];
        if ((100 - progresses[i]) % speeds[i]) curT++;
        
        int cnt = 0;
        while (i < N && progresses[i] + speeds[i] * curT >= 100) {
            cnt++;
            i++;
        }
                
        answer.push_back(cnt);
    }
    return answer;
}