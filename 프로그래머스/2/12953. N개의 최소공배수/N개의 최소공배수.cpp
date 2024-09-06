#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int gcd(int x, int y) {
    int r = x % y;
    if (r==0) return y;
    return gcd(y, r);
}

int solution(vector<int> arr) {    
    if (arr.size() == 1) return arr[0];
    
    int answer = arr[0] * arr[1] / gcd(arr[0], arr[1]);
    
    for (int i=2; i<arr.size(); i++) {
        answer = (answer * arr[i]) / gcd(answer, arr[i]);
    }
    
    return answer;
}