#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    
    vector<int> borrow(lost.size()+1, -1);

    for (int i=0; i<reserve.size(); i++){
        for (int j=0; j<lost.size(); j++){
            if (reserve[i] == lost[j]) {
                reserve.erase(reserve.begin() + i);
                lost.erase(lost.begin() + j);
                i--;
                break;
            }
        }
    }
    int cnt = 0;
    sort(lost.begin(), lost.end());
    sort(reserve.begin(), reserve.end());
    
    for (int i=0; i<lost.size(); i++){
        for (int j=0; j<reserve.size(); j++){
            if (reserve[j] -1 == lost[i]){
                cnt++;
                borrow[i+1] = reserve[j];
                break;
            }
            
            else if (borrow[i] != reserve[j] && reserve[j] + 1 == lost[i]){
                cnt++;
                borrow[i+1] = reserve[j];
                break;
            }
            
            else if (reserve[j] - lost[i] > 1) break;
        }
    }
    
    answer = n - lost.size() + cnt;
    return answer;
}