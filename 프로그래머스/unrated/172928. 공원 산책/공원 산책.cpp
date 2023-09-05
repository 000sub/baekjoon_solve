#include <string>
#include <vector>
#include <cstring>
#include <iostream>
using namespace std;

vector<int> solution(vector<string> park, vector<string> routes) {
    vector<int> answer;
    bool m[51][51];
    pair<int, int> s;
    
    memset(m, false, sizeof(m));
    int H = park.size();
    int W = park[0].size();
    for (int i=0; i<H; i++){
        for (int j=0; j<W; j++){
            if ((char)park[i][j] == 'S') s = pair<int,int>(i, j);
            else if ((char)park[i][j] == 'X') m[i][j] = true;
        }
    }
    
    for (int i=0; i<routes.size(); i++){
        char op = routes[i][0];
        int amount = stoi(routes[i].substr(2));
        if (op=='N'){
            if (s.first - amount < 0) continue;
            bool flag = true;
            for (int j=1; j<=amount; j++){
                if (m[s.first-j][s.second]) {
                    flag = false;
                    break;
                }
            }
            
            if (flag) s.first -= amount;
        }
        
        else if (op=='S'){
            if (s.first + amount > H-1) continue;
            bool flag = true;
            for (int j=1; j<=amount; j++){
                if (m[s.first+j][s.second]) {
                    flag = false;
                    break;
                }
            }
            
            if (flag) s.first += amount;
        }
        
        else if (op=='W'){
            if (s.second - amount < 0) continue;
            bool flag = true;
            for (int j=1; j<=amount; j++){
                if (m[s.first][s.second-j]) {
                    flag = false;
                    break;
                }
            }
            
            if (flag) s.second -= amount;
        }    
        
        else if (op=='E'){
            if (s.second + amount > W-1) continue;
            bool flag = true;
            for (int j=1; j<=amount; j++){
                if (m[s.first][s.second+j]) {
                    flag = false;
                    break;
                }
            }
            
            if (flag) s.second += amount;
        }    
    }
    
    answer.emplace_back(s.first);
    answer.emplace_back(s.second);
    return answer;
}