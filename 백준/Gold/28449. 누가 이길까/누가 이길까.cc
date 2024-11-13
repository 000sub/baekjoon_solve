#include <bits/stdc++.h>
#include <unordered_set>
#define PII pair<int,int>
using namespace std;
typedef long long ll;

int N, M;
vector<int> A, B;
ll win = 0, lose = 0, ties = 0;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N >> M;

    int temp;
    for (int i = 0; i < N; i++) {
        cin >> temp;
        A.push_back(temp);
    }
    for (int i = 0; i < M; i++) {
        cin >> temp;
        B.push_back(temp);
    }

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    for (int i : A) {
        win += lower_bound(B.begin(), B.end(), i) - B.begin();
        ties += upper_bound(B.begin(), B.end(), i) - lower_bound(B.begin(), B.end(), i);
        lose += B.end() - upper_bound(B.begin(), B.end(), i);
    }
    
    cout << win << ' ' << lose << ' ' << ties;


    return 0;
}