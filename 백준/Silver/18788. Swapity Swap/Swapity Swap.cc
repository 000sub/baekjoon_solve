#include <bits/stdc++.h>

#define PII pair<int,int>
#define PFF pair<float, float>

using namespace std;
typedef long long ll;

int arr[101];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, k;
    int a1, a2, b1, b2;
    cin >> n >> k >> a1 >> a2 >> b1 >> b2;

    for (int i = 1; i <= n; i++) arr[i] = i;

    //구간 [a1, a2], 구간 [b1, b2]를 번갈아 뒤집으면 초기 상태로 되돌아가는 사이클이 생성됨을 보장한다.
    int cnt = 0;
    while (1) {
        reverse(arr + a1, arr + a2 + 1);
        reverse(arr + b1, arr + b2 + 1);
        cnt++;
        bool flag = true;
        for (int i = 1; i <= n; i++) {
            if (arr[i] != i) {
                flag = false;
                break;
            }
        }
        if (flag) break;
    }

    k %= cnt;

    while (k--) {
        reverse(arr + a1, arr + a2 + 1);
        reverse(arr + b1, arr + b2 + 1);
    }

    for (int i = 1; i <= n; i++) cout << arr[i] << '\n';

    return 0;
}