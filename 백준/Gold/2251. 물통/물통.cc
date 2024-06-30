#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
#define PII pair<int,int>

using namespace std;


vector<int> answers;
bool visited[201][201];
int a,b,c;

void BFS() {
    queue<PII> q;

    q.push({0,0});
    visited[0][0] = true;
    while (!q.empty()) {
        PII cur = q.front();
        int curC = c - cur.first - cur.second;
        q.pop();


        if (cur.first == 0) {
            answers.push_back(curC);
        }

        
        if (cur.first > 0) {
            // A -> B
            int amount = min(b - cur.second, cur.first);
            int newA = cur.first - amount;
            int newB = cur.second + amount;
            if (!visited[newA][newB]) q.push({newA, newB});
            visited[newA][newB] = true;

            // A -> C
            amount = min(c - curC, cur.first);
            newA = cur.first - amount;
            if (!visited[newA][cur.second]) q.push({newA, cur.second});
            visited[newA][cur.second] = true;
        }

        if (cur.second > 0) {
            // B -> A
            int amount = min(a - cur.first, cur.second);
            int newA = cur.first + amount;
            int newB = cur.second - amount;
            if (!visited[newA][newB]) q.push({newA, newB});
            visited[newA][newB] = true;

            // B -> C
            amount = min(c - curC, cur.second);
            newB = cur.second - amount;
            if (!visited[cur.first][newB]) q.push({cur.first, newB});
            visited[cur.first][newB] = true;
        }

        
        if (curC > 0) {
            // C -> A
            int amount = min(a - cur.first, curC);
            int newA = cur.first + amount;
            if (!visited[newA][cur.second]) q.push({newA, cur.second});
            visited[newA][cur.second] = true;

            // C -> B
            amount = min(b - cur.second, curC);
            int newB = cur.second + amount;
            if (!visited[cur.first][newB]) q.push({cur.first, newB});
            visited[cur.first][newB] = true;
        }

    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> a >> b >> c;

    BFS();

    sort(answers.begin(), answers.end());

    for (int ans : answers) cout << ans << " ";
    cout<<'\n';

    return 0;
}