#include <bits/stdc++.h>

#define PII pair<int,int>
#define PIII pair<int,PII>

using namespace std;
typedef long long ll;

int N;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;

    int i = 1;

    while (N > i) {
        N -= i++;
    }

    if (i % 2 == 1) cout << i + 1 - N << '/' << N << '\n';
    else cout << N << '/' << i + 1 - N << '\n';

    return 0;
}                                                                                                                                                                                                             