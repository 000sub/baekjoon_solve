#include <bits/stdc++.h>
#define PII pair<int,int>

using namespace std;
typedef long long ll;

vector<PII> treeMap[11][11];
int foodMap[11][11], A[11][11];
int N, M, K;
int dx[] = { -1,-1,-1,0,0,1,1,1 };
int dy[] = { 1,0,-1,1,-1,1,0,-1 };

void spring_summer_winter() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int foodFromDead = 0;

            for (int k = treeMap[i][j].size()-1; k>=0 ; k--) {
                int age = treeMap[i][j][k].first;
                int cnt = treeMap[i][j][k].second;
                int sum = age * cnt;
                if (foodMap[i][j] >= sum) {
                    foodMap[i][j] -= sum;
                    treeMap[i][j][k].first++;
                }
                else {
                    int aliveCnt = foodMap[i][j] / age;
                    int deadCnt = cnt - aliveCnt;
                    foodFromDead += deadCnt * (age / 2);
                    if (aliveCnt == 0) {
                        if (K == 1) {
                            cout << "";
                        }
                        treeMap[i][j].erase(treeMap[i][j].begin() + k);
                    }
                    else {
                        foodMap[i][j] -= aliveCnt * age;
                        treeMap[i][j][k].second = aliveCnt;
                        treeMap[i][j][k].first++;
                    }
                }
            }
            foodMap[i][j] += foodFromDead + A[i][j];
        }
    }
    
}

void fall() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (PII& p : treeMap[i][j]) {
                int age = p.first;
                int cnt = p.second;
                if (age % 5 != 0) continue;

                for (int d = 0; d < 8; d++) {
                    int nx = i + dx[d];
                    int ny = j + dy[d];
                    if (nx<0 || ny<0 || nx>N - 1 || ny>N - 1) continue;
                    if (treeMap[nx][ny].empty() || treeMap[nx][ny].back().first != 1)
                        treeMap[nx][ny].push_back({ 1, cnt });
                    else
                        treeMap[nx][ny].back().second += cnt;
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M >> K;
    for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) cin >> A[i][j], foodMap[i][j] = 5;  
    for (int i = 0,x,y,z; i < M; i++) {
        cin >> x >> y >> z;
        treeMap[x-1][y-1].push_back({z, 1});
    }
    while (K--) {
        spring_summer_winter();
        fall();
    }
    int ans = 0;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            for (PII& p : treeMap[i][j]) ans += p.second;
    cout << ans;
    return 0;
}