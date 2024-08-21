#include <bits/stdc++.h>
#define PII pair<int,int>

using namespace std;
typedef long long ll;

vector<int> treeMap[11][11];
vector<int> deadTreeMap[11][11];
int foodMap[11][11], A[11][11];
int N, M, K;
int dx[] = { -1,-1,-1,0,0,1,1,1 };
int dy[] = { 1,0,-1,1,-1,1,0,-1 };

void spring() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            vector<int> tempVec;
            vector<int>& cur = treeMap[i][j];

            sort(cur.begin(), cur.end());

            for (int age : cur) {
                if (age <= foodMap[i][j]) {
                    foodMap[i][j] -= age;
                    tempVec.push_back(age + 1);
                }
                else {
                    deadTreeMap[i][j].push_back(age);
                }
            }

            cur = tempVec;
        }
    }
    
}

void summer() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            vector<int>& cur = deadTreeMap[i][j];
            if (cur.empty()) continue;

            for (int age : cur) {
                foodMap[i][j] += age / 2;
            }

            cur.clear();
        }
    }
}

void fall() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            vector<int>& cur = treeMap[i][j];
            for (int age : cur) {
                if (age % 5 != 0) continue;

                for (int d = 0; d < 8; d++) {
                    int nx = i + dx[d];
                    int ny = j + dy[d];

                    if (nx<0 || ny<0 || nx>N - 1 || ny>N - 1) continue;
                    treeMap[nx][ny].push_back(1);
                }
            }
        }
    }
}

void winter() {
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            foodMap[i][j] += A[i][j];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M >> K;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> A[i][j];
        }
        fill(foodMap[i], foodMap[i] + N, 5);
    }

    int x, y, z;
    for (int i = 0; i < M; i++) {
        cin >> x >> y >> z;
        treeMap[x-1][y-1].push_back(z);
    }

    for (int i=0; i<N; i++)
        for (int j=0; j<N; j++)
            sort(treeMap[i][j].begin(), treeMap[i][j].end());

    while (K--) {
        spring();
        summer();
        fall();
        winter();
    }
    int ans = 0;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            ans += treeMap[i][j].size();
    cout << ans;
    return 0;
}