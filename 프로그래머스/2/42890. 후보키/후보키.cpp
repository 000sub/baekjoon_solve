#include <string>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <iostream>

using namespace std;

int answer = 0;
vector<int> passed;

bool check_combination(int bits, int size, vector<vector<string>>& relation) {
    vector<int> indexes;
    int original_bits = bits;
    
    for (int i= size - 1; i>=0; i--, bits>>=1){
        if (bits & 1) {
            indexes.push_back(i);
        }
    }
        
    for (int i=0; i<relation.size() - 1; i++) {
        for (int j=i+1; j<relation.size(); j++) {
            vector<string>& first = relation[i], second = relation[j];
            
            bool flag = false;
            for (int k=0; k<indexes.size(); k++) {
                int cur_idx = indexes[k];
                if (first[cur_idx] != second[cur_idx]) flag = true;
            }
            
            if (!flag) return false;
        }
    }
    
    //최소성 검증
    for (int passed_bits : passed) {
        if ((passed_bits & original_bits) == passed_bits) return false;
    }
    
    return true;
}

int solution(vector<vector<string>> relation) {
    
    int col_size = relation[0].size();
    
    if (relation.size() == 1) return col_size;
    int max_bits = (1<<col_size) - 1;
    
    for (int i=1; i <= max_bits; i++) {
        if (check_combination(i, col_size, relation)) {
            passed.push_back(i);
            // cout<<"PASSED="<<i<<'\n';
            answer++;
        }
    }
    
    
    
    return answer;
}