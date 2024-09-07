#include <bits/stdc++.h>

#define PII pair<int,int>
#define PIII pair<int,PII>

using namespace std;
typedef long long ll;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string ans = "";
    char c;

    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 15; j++) {
            cin >> c;
            if (ans.empty()) {
                if (c == 'w') ans = "chunbae";
                else if (c == 'b') ans = "nabi";
                else if (c == 'g') ans = "yeongcheol";
            }
        }
    }
    cout << ans;

    
    return 0;
}