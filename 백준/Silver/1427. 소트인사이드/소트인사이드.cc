#include <bits/stdc++.h>

#define PII pair<int,int>
#define PIII pair<int,PII>

using namespace std;
typedef long long ll;

int N;
int cnt[10];

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;

    for (; N > 0; N/=10) {
        cnt[N % 10]++;
    }
    for (int i = 9; i >= 0; i--) {
        for (int j = 0; j < cnt[i]; j++) cout << i;
    }

    return 0;
}                                                                                                                                                                                                             