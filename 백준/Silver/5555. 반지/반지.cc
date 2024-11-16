#include <bits/stdc++.h>
#include <unordered_set>
#define PII pair<int,int>
using namespace std;
typedef long long ll;

int N, cnt = 0;
string pat, str;


int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> pat >> N;
    for (int i = 0; i < N; i++) {
        cin >> str;
        str += str;

        for (int j = 0; j <= 20 - pat.size(); j++) {
            if (pat == str.substr(j, pat.size())) {
                cnt++;
                break;
            }
        }
    }
    cout << cnt;    
    return 0;
}