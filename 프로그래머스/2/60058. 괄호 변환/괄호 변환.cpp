#include <string>
#include <vector>
#include <stack>
using namespace std;


//인자로 균형잡힌 괄호 문자열을 가정함
bool check_right_str(string s) {
    int N = s.size();
    int lcnt=0, rcnt=0;
    
    for (int i=0; i<N; i++) {
        (s[i] == '(') ? lcnt++ : rcnt++;
        if (rcnt > lcnt) return false;
    }
    
    return true;
}

string reverse_str(string s) {
    int N = s.size();
    
    for (int i=0; i<N; i++){
        if (s[i] == '(') s[i] = ')';
        else s[i] = '(';
    }
    
    return s;
}

string split_str(string s) {
    int lcnt=0, rcnt=0;
    string u, v;
    
    int N = s.size();
    
    if (N == 0) return s;
    
    for (int i=0; i<N; i++) {
        (s[i] == '(') ? lcnt++ : rcnt++;
        if (lcnt == rcnt) {
            u = s.substr(0, i+1);
            v = s.substr(i+1);
            break;
        }
    }
    
    if (check_right_str(u)) return u + split_str(v);
    else {
        string temp = "(";
        temp += split_str(v);
        temp += ")";
        u = u.substr(1, u.size()-2);
        u = reverse_str(u);
        temp += u;
        return temp;
    }
}

string solution(string p) {
    return split_str(p);
}