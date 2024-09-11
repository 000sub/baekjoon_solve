#include <string>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

set<string> SET;

bool solution(vector<string> phone_book) {    
    sort(phone_book.begin(), phone_book.end(), [](string& a, string& b){return a.length() < b.length();});
    
    int minSize = phone_book[0].length();
    
    for (string& s : phone_book) {
        SET.insert(s);
        if (s.length() == minSize) continue;
        
        for (int i=minSize; i<s.length(); i++) {
            if (SET.count(s.substr(0, i))) return false;
        }
    }
    return true;
}