#include <bits/stdc++.h>
#include <unordered_set>
#define PII pair<int,int>
using namespace std;
typedef long long ll;

int N, W, L;
queue<int> q;
deque<PII> bridge;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N >> W >> L;
    for (int i = 0, temp; i < N; i++) {
        cin >> temp;
        q.push(temp);
    }

    int ans = 0;

    while (!q.empty() || !bridge.empty()) {
        for (auto& p : bridge) p.second--;
        if (!bridge.empty() && bridge.front().second == 0) bridge.pop_front();
        
        int total = 0;
        for (auto p : bridge) total += p.first;

        if (!q.empty() && q.front() + total <= L && bridge.size() < W) {
            bridge.push_back({ q.front(), W });
            q.pop();
        }
        ans++;
    }
    cout << ans;
    return 0;
}