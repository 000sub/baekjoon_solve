#include <string>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

map<string, int> a, b;
set<string> SET;

int solution(string str1, string str2) {    
    int x = 0, y = 0;
    
    for (int i=0; i<str1.size()-1; i++) {
        char c1 = str1[i];
        char c2 = str1[i+1];
        if (!isalpha(c1) || !isalpha(c2)) continue;
        
        c1 = toupper(c1);
        c2 = toupper(c2);
        
        string cur = "";
        cur += c1;
        cur += c2;
        
        a[cur]++;
        SET.insert(cur);
    }
    
    for (int i=0; i<str2.size()-1; i++) {
        char c1 = str2[i];
        char c2 = str2[i+1];
        if (!isalpha(c1) || !isalpha(c2)) continue;
        
        c1 = toupper(c1);
        c2 = toupper(c2);
        
        string cur = "";
        cur += c1;
        cur += c2;
        b[cur]++;
        SET.insert(cur);
    }
    
    for (auto s : SET) {
        x += min(a[s], b[s]);
        y += max(a[s], b[s]);
    }
    
    if (x==0 && y==0) return 65536;
    
    int answer = (int)((double)x/y * 65536.0);
    return answer;
}