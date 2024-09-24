#include <bits/stdc++.h>

#define PII pair<int,int>
#define PIII pair<int,PII>

using namespace std;
typedef long long ll;

int N;
int arr[14];
vector<int> v;

void dfs(int idx) {
    if (v.size() == 6) {
        for (int i : v) cout << i << " ";
        cout << '\n';
        return;
    }

    for (int i = idx; i < N; i++) {
        v.push_back(arr[i]);
        dfs(i+1);
        v.pop_back();
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    while (true) {
        cin >> N;
        if (N == 0) break;
        for (int i = 0; i < N; i++) cin >> arr[i];
        dfs(0);
        cout << '\n';
    }

    return 0;
}