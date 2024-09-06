#include <iostream>
#include <algorithm>

#define PII pair<int,int>

using namespace std;
typedef long long ll;

int N;

int main(void) {
	ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>N;

    while (N>1) {
        for (int i=2; i<=N; i++) {
            if (N%i == 0) {
                cout<<i<<'\n';
                N/=i;
                break;
            }
        }
    }

	return 0;
}