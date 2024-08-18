#include <string>
#include <vector>
using namespace std;

string solution(string s) {
    string answer = "";
    
    bool isFirstLetter = true;
    
    for (char c : s) {
        if (isFirstLetter) {
            if (isalpha(c)) c = toupper(c);
            if (c != ' ') isFirstLetter = false;
        }
        else {
            if (c == ' ') isFirstLetter = true;
            else c = tolower(c);
        }
        
        answer += c;
    }
    
    return answer;
}