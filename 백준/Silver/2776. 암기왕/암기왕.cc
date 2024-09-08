#include <iostream>
#include <algorithm>
#define PII pair<int,int>

using namespace std;
typedef long long ll;

int T, N, M;
int arr[1000001];

int main(void) {
	ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>T;

    while (T--) {
        cin>>N;
        for (int i=0; i<N; i++) cin>>arr[i];
        sort(arr, arr+N);
        cin>>M;
        int ans = 0;
        for (int i=0, tmp;i<M;i++) {
            cin>>tmp;
            if (binary_search(arr, arr+N, tmp)) cout << 1 << '\n';
            else cout<<0<<'\n';
        }
    }

	return 0;
}