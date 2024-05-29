#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    int N = citations.size();
    sort(citations.begin(), citations.end());
    
    for (int i=N; i>=1; i--) {
        if (citations[N-i] >= i) return i;
    }
    return 0;
}