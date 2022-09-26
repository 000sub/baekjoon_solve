#include <iostream>
#include <algorithm>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int arr[9];
	for (int i=0;i<9;i++) cin>>arr[i];
	
	sort(arr, arr+9);
	int target=0;
	for (int i=0;i<9;i++) target+=arr[i];
	target-=100;
	
	for (int i=0;i<9;i++){
		for (int j=i+1;j<9;j++){
			if (arr[i]+arr[j] == target){
				for (int k=0;k<9;k++){
					if (k!=i && k!=j) cout<<arr[k]<<'\n';
				}
				return 0;
			}
		}
	}
}