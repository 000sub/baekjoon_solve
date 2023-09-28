#include <string>
#include <vector>
#include <cstring>
#include <iostream>

using namespace std;
bool arr[1000001];

int solution(int n) {
    int answer = 0;
    memset(arr, true, sizeof(arr));
    for (int i=2; i*i<=n; i++){
        if (arr[i]){
            for (int j=i*i; j<=n; j+=i) arr[j] = false;
        }        
    }
    
    for (int i=2; i<=n; i++){
        if (arr[i]) answer++;
        
    }
    return answer;
}