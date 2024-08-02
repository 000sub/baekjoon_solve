#include <bits/stdc++.h>

#define PII pair<int,int>
#define PFF pair<float, float>

using namespace std;
typedef long long ll;

int n;
int arr[21][21];
bool visited[21];
vector<int> s, ops;
int ans = 1e9;

void check() {
    for (int i = 0; i < n; i++) {
        visited[i] ? s.push_back(i) : ops.push_back(i);
    }

    int sSum = 0, opsSum = 0;
    for (int i = 0; i < s.size() - 1; i++) {
        for (int j = i+1; j < s.size(); j++) {
            sSum += arr[s[i]][s[j]] + arr[s[j]][s[i]];
            opsSum += arr[ops[i]][ops[j]] + arr[ops[j]][ops[i]];
        }
    }

    ans = min(ans, abs(sSum - opsSum));
    s.clear(); ops.clear();
}

void BT(int idx, int cnt) {
    if (cnt == n/2) {
        check();
        return;
    }

    for (int i = idx; i < n; i++) {
        if (!visited[i]) {
            visited[i] = true;
            BT(i + 1, cnt + 1);
            visited[i] = false;
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> arr[i][j];

    visited[0] = true;
    BT(1, 1);
    cout << ans;


    return 0;
}