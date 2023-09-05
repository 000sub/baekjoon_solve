#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
    vector<string> answer;
    unordered_map<string, int> rank;
    unordered_map<int, string> id;
    for (int i=0; i<players.size(); i++){
        rank[players[i]] = i+1;
        id[i+1] = players[i];
    }
    
    for (int i=0; i<callings.size(); i++){
        string new_player = callings[i];
        int new_player_rank = rank[new_player];
        string prev_player = id[new_player_rank-1];
        
        rank[new_player] = new_player_rank - 1;
        id[new_player_rank-1] = new_player;
        
        rank[prev_player] = new_player_rank;
        id[new_player_rank] = prev_player;
        
    }
    
    for (int i=0; i<players.size(); i++){
        answer.push_back(id[i+1]);
    }
    return answer;
}