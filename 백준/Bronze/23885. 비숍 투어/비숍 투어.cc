#include <bits/stdc++.h>

#define PII pair<int,int>
#define PIII pair<int,PII>

using namespace std;
typedef long long ll;

int N, M;
int sx, sy, ex, ey;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M >>sx>>sy>>ex>>ey;

    if (sx == ex && sy == ey) cout << "YES";
    else if (N == 1 || M == 1) cout << "NO";
    else if ((abs(sx - ex) + abs(sy - ey)) % 2) cout << "NO";
    else cout << "YES";
    
    return 0;
}