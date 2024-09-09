#include <bits/stdc++.h>

#define PII pair<int,int>
#define PIII pair<int,PII>

using namespace std;
typedef long long ll;

int N;
int cnt[100001];
PII arr[100001];
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> arr[i].first >> arr[i].second;
    }

    sort(arr, arr + N);
    priority_queue<PII, vector<PII>, greater<PII>> pq; //endTime, idx
    priority_queue<PII, vector<PII>, greater<PII>> temp; //idx, endTime

    int num = 0;

    for (int i = 0; i < N; i++) {
        while (!pq.empty()) {
            if (pq.top().first < arr[i].first) {
                temp.push({ pq.top().second, pq.top().first });
                pq.pop();
            }
            else break;
        }

        if (temp.empty()) {
            cnt[++num] = 1;
            pq.push({ arr[i].second, num });
        }
        else {
            int idx = temp.top().first;
            temp.pop();
            pq.push({ arr[i].second, idx });
            cnt[idx]++;
        }   
    }

    cout << num << '\n';
    for (int i = 1; i <= num; i++) cout << cnt[i] << " ";

    
    return 0;
}