#include <string>
#include <vector>

using namespace std;

bool picked[1001], cache[1001];


int solution(int coin, vector<int> cards) {
    int answer = 0;
    int N = cards.size();
    const int KEY = N+1;
    
    for (int i=0; i<N/3; i++) {
        picked[cards[i]] = true;
    }
    
    for (int i=N/3; i<N; i+=2) {
        answer++;
        int first = cards[i];
        int second = cards[i+1];
        
        if (picked[KEY - first] && coin > 0) {
            coin--;
            picked[KEY - first] = false;
            cache[second] = true;
        }
        
        else if (picked[KEY - second] && coin > 0) {
            coin--;
            picked[KEY - second] = false;
            cache[first] = true;
        }
        
        else {
            
            cache[first] = true; cache[second] = true;
            
            bool erased = false;
            
            for (int i=0; i<KEY; i++) {
                if (!erased && picked[i] && picked[KEY - i]) {
                    picked[i] = false; picked[KEY-i] = false;
                    erased = true;
                }
            }
            
            if (!erased && coin > 0) {
                for (int i=0; i<KEY; i++) {
                    if (!erased && picked[i] && cache[KEY - i]) {
                        picked[i] = false; cache[KEY - i] = false;
                        coin--;
                        erased = true;
                    }
                }
                
                if (!erased && coin >= 2) {
                    for (int i=0; i<KEY; i++) {
                        if (!erased && cache[i] && cache[KEY - i]) {
                            cache[i] = false; cache[KEY - i] = false;
                            coin-=2;
                            erased = true;
                        }
                    }
                }
            }
            
            if (!erased) return answer;
        }
        
        if (i+2 >= N) return answer + 1;
    }
    return answer;
}