#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

#define PII pair<int,int>

using namespace std;

int n,m,r,temp;
int arr[301][301];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>n>>m>>r;
    for (int i=0;i<n;i++)
        for (int j=0;j<m;j++)
            cin>>arr[i][j];

    int num = min(n, m) / 2;
    
    while (r--) {
        for (int i=0; i<num; i++) {
            temp = arr[i][i];

            //위쪽
            for (int j=i; j<m-i-1; j++) {
                arr[i][j] = arr[i][j+1];
            }

            //오른쪽
            for (int j=i; j<n-i-1; j++) {
                arr[j][m-1-i] = arr[j+1][m-1-i];
            }

            //아래쪽
            for (int j=m-1-i; j>=i+1; j--) {
                arr[n-1-i][j] = arr[n-1-i][j-1];
            }

            //왼쪽
            for (int j=n-1-i; j>=i+2; j--) {
                arr[j][i] = arr[j-1][i];
            }

            arr[i+1][i] = temp;
        }
    }

    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cout << arr[i][j] << " ";
        }
        cout << '\n';
    }
     
    return 0;
}