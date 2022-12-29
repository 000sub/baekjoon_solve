#include <iostream>
#include <algorithm>

using namespace std;


int N, arr[11];
int max_rst = -1e9, min_rst = 1e9;

void renew(int _rst){
	max_rst = max(max_rst, _rst);
	min_rst = min(min_rst, _rst);
}

void solv(int cur, int rst, int* ops){
	if (cur==N) {
		renew(rst);
		return;
	}
	
	for (int i=0; i<4; i++){
		if (ops[i] > 0) {
			switch (i) {
				case 0:
					ops[i]--;
					solv(cur+1, rst+arr[cur], ops);
					ops[i]++;
					break;
				case 1:
					ops[i]--;
					solv(cur+1, rst-arr[cur], ops);
					ops[i]++;
					break;
				case 2:
					ops[i]--;
					solv(cur+1, rst*arr[cur], ops);
					ops[i]++;
					break;
				case 3:
					ops[i]--;
					solv(cur+1, rst/arr[cur], ops);
					ops[i]++;
					break;
			}
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int op_num[4];
	int ans;
	
	cin>>N;
	for (int i=0;i<N;i++) cin>>arr[i];
	for (int i=0;i<4;i++) cin>>op_num[i];

	solv(1, arr[0], op_num);
	
	cout<<max_rst<<'\n'<<min_rst;
	return 0;
}