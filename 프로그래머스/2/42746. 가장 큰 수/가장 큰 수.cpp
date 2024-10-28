#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(int a, int b) {
    string A = to_string(a);
    string B = to_string(b);
    
    return A + B > B + A;
}

string solution(vector<int> numbers) {
    string answer = "";
    
    sort(numbers.begin(), numbers.end(), cmp);
    
    if (numbers[0] == 0) return "0";
    
    for (int i : numbers) {
        answer += to_string(i);
    }
    
    return answer;
}