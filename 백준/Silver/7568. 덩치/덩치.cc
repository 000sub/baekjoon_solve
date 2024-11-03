#include <bits/stdc++.h>
#include <unordered_set>
#define PII pair<int,int>
using namespace std;
typedef long long ll;

int N;
vector<PII> v;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N;

    for (int i = 0, a, b; i < N; i++) {
        cin >> a >> b;
        v.push_back({ a,b });
    }

    for (int i = 0; i < N; i++) {
        int rank = 1;
        for (int j = 0; j < N; j++) {
            if (v[i].first < v[j].first && v[i].second < v[j].second) rank++;
        }
        cout << rank << ' ';
    }

    return 0;
}