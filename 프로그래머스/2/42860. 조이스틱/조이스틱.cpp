#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int solution(string name) {
    int answer = 0;
    int N = name.size();
    int cnt = N - 1;
    
    for (int i=0; i<N; i++){
        answer += min(name[i] - 'A', 'Z' - name[i] + 1);
        int nearest_i = i+1;
        while (nearest_i < N && name[nearest_i] == 'A') nearest_i++;
        
        cnt = min(cnt, i + N-nearest_i + min(i, N-nearest_i));
    }
    
    answer += cnt;
    return answer;
}