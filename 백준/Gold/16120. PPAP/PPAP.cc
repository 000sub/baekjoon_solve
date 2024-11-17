#include <bits/stdc++.h>
#include <unordered_set>
#define PII pair<int,int>
using namespace std;
typedef long long ll;

string str;
stack<char> st;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> str;
    for (int i = 0; i < str.size(); i++) {
        if (str[i] == 'P') {
            st.push('P');
        }
        else {
            if (i + 1 >= str.size() || str[i + 1] != 'P') {
                cout << "NP";
                return 0;
            }

            for (int k = 0; k < 2; k++) {
                if (st.empty()) {
                    cout << "NP";
                    return 0;
                }
                st.pop();
            }
            st.push('P');
            i++;
        }
    }
    if (st.empty() || st.size() == 1) cout << "PPAP";
    else cout << "NP";
    return 0;
}