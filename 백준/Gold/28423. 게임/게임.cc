#include <bits/stdc++.h>
#include <unordered_set>
#define PII pair<int,int>
using namespace std;
typedef long long ll;

int L, R, ans = 0;
bool visited[100001];

int getDigitSum(int k) {
    int res = 0;
    while (k > 0) {
        res += (k % 10);
        k /= 10;
    }
    return res;
}

int getDigitMul(int k) {
    int res = 1;
    while (k > 0) {
        res *= (k % 10);
        k /= 10;
    }
    return res;
}

int check(int k) {
    memset(visited, false, sizeof(visited));
    int prev = k;
    while (1) {
        if (visited[k]) break;
        visited[k] = true;

        int sum = getDigitSum(k);
        int mul = getDigitMul(k);

        k = stoi(to_string(sum) + to_string(mul));
        if (k > 100000) return -1;
        if (prev == k) return 1;

        prev = k;
    }

    return 0;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> L >> R;

    for (int i = L; i <= R; i++) {
        ans += check(i);
    }
    cout << ans;
    return 0;
}