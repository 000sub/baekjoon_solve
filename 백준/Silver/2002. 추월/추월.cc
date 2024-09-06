#include <bits/stdc++.h>

#define PII pair<int,int>
#define PIII pair<int,PII>

using namespace std;
typedef long long ll;

int N;
unordered_map<string, int> um;
vector<int> v;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    string s;
    for (int i = 0; i < N; i++) {
        cin >> s;
        um[s] = i;
    }
    for (int i = 0; i < N; i++) {
        cin >> s;
        v.push_back(um[s]);
    }
    int cnt = 0;
    for (int i = 0; i < v.size(); i++) {
        bool flag = false;
        for (int j = i + 1; j < v.size(); j++) {
            if (v[i] > v[j]) {
                flag = true;
                break;
            }
        }
        if (flag) cnt++;
    }
    cout << cnt;

    
    return 0;
}