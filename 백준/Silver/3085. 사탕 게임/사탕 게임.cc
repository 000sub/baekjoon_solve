#include <iostream>
#include <algorithm>

using namespace std;

int maxcnt = 1;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin>>n;
    char arr[n+1][n+1];
    
    
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            char c;
            cin >> c;
            arr[i][j] = c;
        }
    }
    
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            if (maxcnt == n) break;
            
            if (j<n){
                //swap and cal
                char temp = arr[i][j];
                arr[i][j] = arr[i][j+1];
                arr[i][j+1] = temp;
                
                int cnt=1;
                char cur = arr[1][j];
                for (int k=2;k<=n;k++){
                    if (arr[k][j] != cur){
                        maxcnt = max(cnt, maxcnt);
                        cnt = 1;
                        cur = arr[k][j];
                    }
                    else {
                        cnt++;
                    }
                }
                maxcnt = max(cnt, maxcnt);
                
                cnt=1;
                cur = arr[1][j+1];
                for (int k=2;k<=n;k++){
                    if (arr[k][j+1] != cur){
                        maxcnt = max(cnt, maxcnt);
                        cnt = 1;
                        cur = arr[k][j+1];
                    }
                    else {
                        cnt++;
                    }
                }
                maxcnt = max(cnt, maxcnt);
                
                cnt=1;
                cur = arr[i][1];
                for (int k=2;k<=n;k++){
                    if (arr[i][k] != cur){
                        maxcnt = max(cnt, maxcnt);
                        cnt = 1;
                        cur = arr[i][k];
                    }
                    else {
                        cnt++;
                    }
                }
                maxcnt = max(cnt, maxcnt);
                
                temp = arr[i][j];
                arr[i][j] = arr[i][j+1];
                arr[i][j+1] = temp;
            }
            
            if (i<n){
                //swap and cal
                char temp = arr[i][j];
                arr[i][j] = arr[i+1][j];
                arr[i+1][j] = temp;
                
                int cnt=1;
                char cur = arr[i][1];
                for (int k=2;k<=n;k++){
                    if (arr[i][k] != cur){
                        maxcnt = max(cnt, maxcnt);
                        cnt = 1;
                        cur = arr[i][k];
                    }
                    else {
                        cnt++;
                    }
                }
                maxcnt = max(cnt, maxcnt);
                
                cnt=1;
                cur = arr[i+1][1];
                for (int k=2;k<=n;k++){
                    if (arr[i+1][k] != cur){
                        maxcnt = max(cnt, maxcnt);
                        cnt = 1;
                        cur = arr[i+1][k];
                    }
                    else {
                        cnt++;
                    }
                }
                maxcnt = max(cnt, maxcnt);
                
                cnt=1;
                cur = arr[1][j];
                for (int k=2;k<=n;k++){
                    if (arr[k][j] != cur){
                        maxcnt = max(cnt, maxcnt);
                        cnt = 1;
                        cur = arr[k][j];
                    }
                    else {
                        cnt++;
                    }
                }
                maxcnt = max(cnt, maxcnt);
                
                temp = arr[i][j];
                arr[i][j] = arr[i+1][j];
                arr[i+1][j] = temp;
            }
        }
    }
    
    cout<<maxcnt<<'\n';

    return 0;
}
