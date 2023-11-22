#include <string>
#include <vector>
#include <deque>
#include <iostream>
using namespace std;

vector<vector<int>> solution(vector<vector<int>> rc, vector<string> operations) {
    string op[2] = {"ShiftRow", "Rotate"};
    int H = rc.size();
    int W = rc[0].size();
    deque<int> first_col, last_col;
    deque<int> rows[H];
    vector<vector<int>> answer(H, vector<int>(W));
    int first_row_idx = 0;
    
    for (int i=0; i<H; i++) {
        for (int j=0; j<W; j++){
            if (j==0) first_col.push_back(rc[i][j]);
            else if (j==W-1) last_col.push_back(rc[i][j]);
            else rows[i].push_back(rc[i][j]);
        }
    }
    
    for (string s : operations) {
        if (s == op[0]){
            first_row_idx = (first_row_idx == 0) ? H-1 : first_row_idx-1;
            first_col.push_front(first_col.back()); first_col.pop_back();
            last_col.push_front(last_col.back()); last_col.pop_back();
        }
        else {
            int last_row_idx = (first_row_idx == 0) ? H-1 : first_row_idx - 1;
            rows[first_row_idx].push_front(first_col.front()); first_col.pop_front();
            last_col.push_front(rows[first_row_idx].back()); rows[first_row_idx].pop_back();
            rows[last_row_idx].push_back(last_col.back()); last_col.pop_back();
            first_col.push_back(rows[last_row_idx].front()); rows[last_row_idx].pop_front();
        }
    }
    
    for (int i=0; i<H; i++) {
        for (int j=0; j<W; j++){
            if (j==0) answer[i][j] = first_col[i];
            else if (j==W-1) answer[i][j] = last_col[i];
            else answer[i][j] = (first_row_idx + i > H-1) ? rows[first_row_idx+i-H][j-1] : rows[first_row_idx+i][j-1];
        
        }
    }
    return answer;
}