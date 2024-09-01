#include <bits/stdc++.h>

#define PII pair<int,int>
#define PIII pair<int,PII>

using namespace std;
typedef long long ll;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    string s;
    cin >> s;
    int n = s.size();
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (
            (s[i] == 'c' && i + 1 < n && (s[i + 1] == '=' || s[i + 1] == '-')) ||
            (s[i] == 'l' && i + 1 < n && s[i + 1] == 'j') ||
            (s[i] == 'n' && i + 1 < n && s[i + 1] == 'j') ||
            (s[i] == 's' && i + 1 < n && s[i + 1] == '=') ||
            (s[i] == 'z' && i + 1 < n && s[i + 1] == '=') || 
            (s[i] == 'd' && i + 1 < n && s[i + 1] == '-')
           ) {
                ans++;
                i++;
        }
        
        else if (s[i] == 'd' && i + 2 < n && s[i + 1] == 'z' && s[i + 2] == '=') {
            ans++;
            i += 2;
        }
            else ans++;
        
    }

    cout << ans;
    return 0;
}