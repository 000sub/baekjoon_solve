#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer;
    answer.emplace_back(0);
    answer.emplace_back(0);
    
    int N = sequence.size();
    int minlen = 1e9;
    int lo=0, hi=0, sum=sequence[0];
    
    while (lo<N && hi<N){
        if (sum < k) sum += sequence[++hi];
        else if (sum > k) sum -= sequence[lo++];
        else {
            if (minlen > hi - lo){
                minlen = hi - lo;
                answer[0] = lo;
                answer[1] = hi;
            }
            sum += sequence[++hi];
        }
    }
    return answer;
}