#include <bits/stdc++.h>
#include <unordered_set>
#define PII pair<int,int>
using namespace std;
typedef long long ll;

int N, M, P;
int S[10], ans[10];
char arr[1001][1001];
vector<PII> v[10];

int dx[] = { 0,1,0,-1 };
int dy[] = { 1,0,-1,0 };


int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> N >> M >> P;
    for (int i = 1; i <= P; i++) cin >> S[i];

    char ch;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> arr[i][j];
            if (arr[i][j] != '.' && arr[i][j] != '#') {
                ans[arr[i][j] - '0']++;
                v[arr[i][j] - '0'].push_back({ i, j });
            }
        }
    }

    while (1) {
        int total = 0;
        for (int i = 1; i <= P; i++) {
            for (int j = 0; j < S[i]; j++) {
                vector<PII> nextV;
                int cnt = 0;
                
                for (PII& p : v[i]) {
                    for (int d = 0; d < 4; d++) {
                        int nx = p.first + dx[d];
                        int ny = p.second + dy[d];

                        if (nx < 0 || ny < 0 || nx >= N || ny >= M || arr[nx][ny] != '.') continue;
                        nextV.push_back({ nx, ny });
                        arr[nx][ny] = i + '0';
                        total++; cnt++; ans[i]++;
                    }
                }

                if (cnt == 0) break;
                v[i] = nextV;
            }
        }
        if (total == 0) break;
    }

    for (int i = 1; i <= P; i++) cout << ans[i] << " ";


    return 0;
}