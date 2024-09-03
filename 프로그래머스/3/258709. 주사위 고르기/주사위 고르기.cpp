#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> aDices, bDices, aRolls, bRolls;
int n, ans = 0;
vector<vector<int>> DICE;
vector<int> ansV;

void selectRoll(int idx, int sum, vector<int>& dices, vector<int>& rolls) {
    if (idx == n/2) {
        rolls.push_back(sum);
        return;
    }
    
    for (int i=0; i<6; i++) {
        selectRoll(idx+1, sum + DICE[dices[idx]][i], dices, rolls);
    }
}

void simulate() {
    int locAns = 0;
    
    selectRoll(0, 0, aDices, aRolls);
    selectRoll(0, 0, bDices, bRolls);
    
    sort(bRolls.begin(), bRolls.end());
    
    for (int i=0; i<aRolls.size(); i++) {
        int wins = lower_bound(bRolls.begin(), bRolls.end(), aRolls[i]) - bRolls.begin();
        locAns += wins;
    }
        
    if (locAns > ans) {
        ans = locAns;
        ansV.clear();
        for (int i : aDices) {
            ansV.push_back(i+1);
        }
    }
    
    aRolls.clear();
    bRolls.clear();
}

void selectDice(int idx) {    
    if (idx == n) {
        if (aDices.size() == n/2) simulate();
        return;
    }
    
    bDices.push_back(idx);
    selectDice(idx+1);
    bDices.pop_back();
    
    aDices.push_back(idx);
    selectDice(idx+1);
    aDices.pop_back();
}

vector<int> solution(vector<vector<int>> dice) {
    n = dice.size();
    DICE = dice;
    
    selectDice(0);
    
    return ansV;
}