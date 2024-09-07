#include <bits/stdc++.h>

#define PII pair<int,int>
#define PIII pair<int,PII>

using namespace std;
typedef long long ll;

int N, M;
string s;
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M >> s;

    int cnt = 0, ans = 0;
    for (int i = 0; i < M; i++) {
        if (s[i] == 'I') {
            while (i+2<M && s[i + 1] == 'O' && s[i + 2] == 'I') {
                cnt++;
                i += 2;
                if (cnt == N) ans++, cnt--;
            }
            cnt = 0;
        }
    }

    cout << ans;
    
    return 0;
}