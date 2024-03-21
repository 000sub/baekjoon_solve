#include <string>
#include <vector>

using namespace std;

const int MAX = 1'000'000;

vector<int> solution(vector<vector<int>> edges) {
    vector<int> answer;
    vector<int> from[MAX+1], to[MAX+1];
    int start = -1;
    int doughnut_cnt = 0, stick_cnt = 0, eight_cnt = 0;
    
    for (vector<int>& edge : edges){
        int s = edge[0];
        int e = edge[1];
        
        from[s].push_back(e);
        to[e].push_back(s);
    }
    
    //시작점 판별
    for (int i=0; i<MAX+1; i++) {
        if (from[i].size() > 0 && to[i].size() == 0) {
            if (start == -1) start = i;
            else if (from[i].size() > from[start].size()) start = i;
        }
    }
    
    //각 서브 그래프를 판별
    for (int st : from[start]) {
                
        //막대 그래프의 시작과 끝
        if (from[st].size() == 0 || to[st].size() == 0) {
            stick_cnt++;
        }
        //2개의 외향 간선 존재 시 8자 그래프
        else if (from[st].size() > 1) {
            eight_cnt++;
        }
        //도넛 그래프 크기 1
        else if (from[st][0] == st) {
            doughnut_cnt++;
        }
        //도넛, 막대, 8자 중간 노드에서 구분 로직
        else {
            int temp = from[st][0];
            while (temp != st && from[temp].size() == 1) temp = from[temp][0];
            
            //되돌아오지 못함
            if (temp != st) {
                //외향 간선 2개인 경우 8자
                if (from[temp].size() > 1) eight_cnt++;
                //외향 간선 0개인 경우 막대의 끝
                else if (from[temp].size() == 0) stick_cnt++;
            }
            //되돌아옴
            else {
                doughnut_cnt++;
            }
            // (temp != st) ? eight_cnt++ : ((from[temp].size() == 1) ? doughnut_cnt++ : stick_cnt++);
        }
    }
    
    answer.push_back(start);
    answer.push_back(doughnut_cnt);
    answer.push_back(stick_cnt);
    answer.push_back(eight_cnt);
    return answer;
}