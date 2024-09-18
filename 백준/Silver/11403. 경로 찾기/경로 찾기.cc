#include <bits/stdc++.h>

#define PII pair<int,int>
#define PIII pair<int,PII>

using namespace std;
typedef long long ll;

int N;
int visited[101];
vector<int> adjs[101];

void dfs(int x) {
    for (int next : adjs[x]) {
        if (!visited[next]) {
            visited[next] = true;
            dfs(next);
        }
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    int tmp;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> tmp;
            if (tmp == 1) adjs[i].push_back(j);
        }
    }

    for (int i = 0; i < N; i++) {
        memset(visited, false, sizeof(visited));
        dfs(i);
        for (int j = 0; j < N; j++) cout << visited[j] << " ";
        cout << '\n';
    }

    return 0;
}