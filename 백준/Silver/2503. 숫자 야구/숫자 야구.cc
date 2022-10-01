#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int arr[1000] = {0};
	int n, tmp, s, b;
	int cnt = 0;
	string tmp_str;
	cin>>n;
	
	for (int i=0;i<n;i++){
		cin>>tmp>>s>>b;
		tmp_str = to_string(tmp);
		
		for (int k=123;k<1000;k++){
			int t_s=0;
			int t_b=0;
			string cur = to_string(k);
			
			if (cur[0] == '0' || cur[1] =='0' || cur[2]=='0'){
				arr[k]=1;
				continue;
			}
			
			if (cur[0] == cur[1] || cur[1]==cur[2] || cur[0]==cur[2]){
				arr[k] = 1;
				continue;
			}
			
			for (int m=0;m<3;m++){
				for (int n=0;n<3;n++){
					if (tmp_str[m]==cur[n]){
						if (m==n) t_s++;
						else t_b++;
					}
				}
			}
			
			
			if (t_s!=s || t_b!=b) arr[k] = 1;
		}
	}
	
	for (int i=123;i<1000;i++){
		if (arr[i]==0) cnt++;
	}
	
	cout<<cnt;
	
}