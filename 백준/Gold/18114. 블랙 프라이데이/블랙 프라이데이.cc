#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, C;
    bool flag = false;
    cin>>N>>C;

    vector<int> arr(N);
    for(int i=0; i<N; i++) {
        cin>>arr[i];
    }

    sort(arr.begin(), arr.end());

    if (binary_search(arr.begin(), arr.end(), C)) {
        cout<<1<<'\n';
        return 0;
    }

    for (int i=0; i<N; i++) {
        if (arr[i] != C-arr[i] && binary_search(arr.begin(), arr.end(), C-arr[i])) {
            cout<<1<<'\n';
            return 0;
        }

        for (int j=i+1; j<N; j++) {
            if (C-arr[i]-arr[j] != arr[i] && C-arr[i]-arr[j] != arr[j] && binary_search(arr.begin(), arr.end(), C-arr[i]-arr[j])) {
                cout<<1<<'\n';
                return 0;
            }
        }
    }

    cout<<0<<'\n';

    return 0;
}
