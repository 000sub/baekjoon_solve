#include <bits/stdc++.h>

#define PII pair<int,int>
#define PFF pair<float, float>

using namespace std;
typedef long long ll;

bool visited[26];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, cnt = 0;
    string s;
    cin >> n;

    while (n--) {
        cin >> s;
        memset(visited, false, sizeof(visited));

        bool flag = false;
        for (int i = 0; i < s.size(); i++) {
            if (visited[s[i] - 'a'] && s[i-1] != s[i]) {
                flag = true;
                break;
            }

            visited[s[i] - 'a'] = true;
        }

        if (!flag) cnt++;
    }
    cout << cnt;
    return 0;
}