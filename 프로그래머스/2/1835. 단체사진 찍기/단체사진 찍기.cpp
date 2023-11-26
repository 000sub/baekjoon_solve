#include <string>
#include <vector>
#include <cstring>
#include <cmath>
using namespace std;

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int answer;
bool selected[8];
const char friends[8] = {'A', 'C', 'F', 'J', 'M', 'N', 'R', 'T'};
vector<string> D;
vector<char> line;

bool check(){
    for (string s : D) {
        char c1 = s[0];
        char c2 = s[2];
        char op = s[3];
        int amount = s[4] - '0' + 1;
        
        int idx1 = -1, idx2 = -1;
        for (int i=0; i<8; i++){
            if (c1 == line[i]) idx1 = i;
            else if (c2 == line[i]) idx2 = i;
        }
        
        int gap = abs(idx1 - idx2);
        
        if ((op == '=' && gap != amount) || 
            op == '>' && gap <= amount ||
            op == '<' && gap >= amount)
            return false;
    }
    
    return true;
}

void solve(int idx){
    if (idx == 8) {
        if (check()) answer++;
        return;
    }
    
    for (int i=0; i<8; i++){
        if (!selected[i]) {
            selected[i] = true;
            line[idx] = friends[i];
            solve(idx+1);
            selected[i] = false;
        }
    }
    
    
}
int solution(int n, vector<string> data) {
    line.clear(); line.resize(8);
    D=data; answer=0;
    memset(selected, false, sizeof(selected));
    solve(0);
    return answer;
}