#include <bits/stdc++.h>

#define PII pair<int,int>
using namespace std;
typedef long long ll;

ll A, B;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> A >> B;
    if (A < B) swap(A, B);
    cout << (A + B) * (A-B+1) / 2;

    return 0;
}