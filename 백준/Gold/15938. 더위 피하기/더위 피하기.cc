#include <bits/stdc++.h>

#define PII pair<int,int>
#define PIII pair<int,PII>

using namespace std;
typedef long long ll;

ll dp[401][401][201];
int sx, sy, hx, hy, T, N;
const int MOD = 1e9 + 7;
const int delta = 1e5;
map<PII, bool> bars;

int dx[] = { 0,1,0,-1 };
int dy[] = { -1,0,1,0 };

ll run(int x, int y, int curT) {
    int nx = sx + x;
    int ny = sy + y;
    if (nx == hx && ny == hy) return 1;
    if (abs(nx - hx) + abs(ny - hy) > T - curT) return 0;
    if (curT == T) return 0;

    ll& cur = dp[x + 200][y + 200][curT];
    if (cur != -1) return cur;
    cur = 0;

    for (int d = 0; d < 4; d++) {
        int nnx = nx + dx[d];
        int nny = ny + dy[d];
        if (!bars[{nnx, nny}]) {
            cur = (cur + (run(x + dx[d], y + dy[d], curT + 1) % MOD)) % MOD;
        }
    }

    return cur;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> sx >> sy >> T >> hx >> hy >> N;
    sx += delta;
    sy += delta;
    hx += delta;
    hy += delta;
    for (int i = 0, a, b; i < N; i++) {
        cin >> a >> b;
        bars[{a + delta, b + delta}] = true;
    }

    memset(dp, -1, sizeof(dp));

    cout << run(0, 0, 0) % MOD;
    return 0;
}