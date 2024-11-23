#include <bits/stdc++.h>
#include <unordered_set>
#define PII pair<int,int>
using namespace std;
typedef long long ll;

int N, M;
int A[100001];
deque<int> dq;


int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++) cin >> A[i];
    
    for (int i = 0, temp; i < N; i++) {
        cin >> temp;
        if (A[i] == 0) dq.push_back(temp);
    }
    cin >> M;
    for (int i = 0, temp; i < M; i++) {
        cin >> temp;
        dq.push_front(temp);
        cout << dq.back() << " ";
        dq.pop_back();
    }


    return 0;
}