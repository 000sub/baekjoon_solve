#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <sstream>

using namespace std;

int solution(vector<string> friends, vector<string> gifts) {
    
    unordered_map<string, int> friend_idx_map;
    unordered_map<int, int> give_cnt;
    unordered_map<int, int> receive_cnt;
    unordered_map<int, int> result_cnt;
    
    int N = friends.size();
    
    int give_graph[N][N];
    
    for (int i=0; i<N; i++)
        for (int j=0; j<N; j++)
            give_graph[i][j] = 0;
    
    
    for (int i=0; i<N; i++){
        friend_idx_map[friends[i]] = i;
        give_cnt[i]; receive_cnt[i]; result_cnt[i];
    }
    for (string gift : gifts){
        istringstream ss(gift);
        string from, to;
        ss >> from >> to;
        give_graph[friend_idx_map[from]][friend_idx_map[to]]++;
        give_cnt[friend_idx_map[from]]++;
        receive_cnt[friend_idx_map[to]]++;
    }
    
    for (int i=0; i<N-1; i++) {
        for (int j=i+1; j<N; j++) {
            if (give_graph[i][j] > give_graph[j][i]) result_cnt[i]++;
            else if (give_graph[i][j] < give_graph[j][i]) result_cnt[j]++;
            else {
                int score_i = give_cnt[i] - receive_cnt[i];
                int score_j = give_cnt[j] - receive_cnt[j];
                
                if (score_i > score_j) result_cnt[i]++;
                else if (score_i < score_j) result_cnt[j]++;
            }
        }
    }
    
    int answer = 0;
    
    for (int i=0; i<N; i++){
        answer = max(answer, result_cnt[i]);
    }
    
    return answer;
}