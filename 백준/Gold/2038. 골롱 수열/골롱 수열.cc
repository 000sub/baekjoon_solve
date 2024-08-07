#include <bits/stdc++.h>

#define PII pair<int,int>
#define PFF pair<float, float>

using namespace std;
typedef long long ll;

const int MAX = 10000000;
int arr[MAX];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    int a = 0, b = 0, cur = 1;
    while (b < n) {
        a++;
        if (arr[a] == 0) {
            arr[a] = cur;
            for (int i = 1; i < arr[cur]; i++) {
                arr[a + i] = cur;
            }
            cur++;
        }
        b += arr[a];
    }

    cout << a;

    return 0;
}