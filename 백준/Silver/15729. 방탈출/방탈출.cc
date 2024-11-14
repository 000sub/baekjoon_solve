#include <bits/stdc++.h>
#include <unordered_set>
#define PII pair<int,int>
using namespace std;
typedef long long ll;

int N, ans = 0;
vector<int> v;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N;
    for (int i = 0, temp; i < N; i++) {
        cin >> temp;
        v.push_back(temp);
    }

    for (int i = 0; i < N; i++) {
        if (v[i] == 1) {
            ans++;

            if (i+1 < N) v[i + 1] = 1 - v[i + 1];
            if (i+2 < N) v[i + 2] = 1 - v[i + 2];
        }
    }

    cout << ans;
    return 0;
}