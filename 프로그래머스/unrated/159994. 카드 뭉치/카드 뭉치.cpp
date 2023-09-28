#include <string>
#include <vector>

using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    string answer = "";
    int idx1 = 0, idx2 = 0, gidx = 0;
    
    while (gidx < goal.size()) {
        string s = goal[gidx];
        if (cards1[idx1] == goal[gidx]) idx1++;
        else if (cards2[idx2] == goal[gidx]) idx2++;
        else break;
        gidx++;
    }
    
    answer = gidx==goal.size() ? "Yes" : "No";
    
    return answer;
}