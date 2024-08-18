#include <bits/stdc++.h>

#define PII pair<int,int>
#define PFF pair<float, float>

using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int w, h, p, q, t;
    cin >> w >> h >> p >> q >> t;

    //x좌표, y좌표의 시간상 위치는 2w, 2h의 사이클을 가짐
    p = (p + t) % (2 * w);
    q = (q + t) % (2 * h);

    //길이를 초과한다면, 반대 방향
    if (p > w) p = w - (p-w);
    if (q > h) q = h - (q-h);

    cout << p << " " << q;

    return 0;
}