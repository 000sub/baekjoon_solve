//kmp 사용

#include <bits/stdc++.h>

#define PII pair<int,int>
#define PIII pair<int,PII>

using namespace std;
typedef long long ll;

int N, M;
int fail[1000001];
string T, P;

void build() {
    for (int i = 1, j=0; i < M; i++) {
        while (j > 0 && P[i] != P[j]) j = fail[j - 1];
        if (P[i] == P[j]) fail[i] = ++j;
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    getline(cin, T);
    getline(cin, P);

    N = T.size();
    M = P.size();

    build();
    vector<int> ans;

    for (int i = 0, j = 0; i < N; i++) {
        while (j > 0 && T[i] != P[j]) j = fail[j-1];
        if (T[i] == P[j]) {
            if (j == M - 1) {
                ans.push_back(i - M + 1);
                j = fail[j];
            }
            else j++;
        }
    }
    cout << ans.size() << '\n';
    for (int i : ans) cout << i+1 << '\n';
    return 0;
}