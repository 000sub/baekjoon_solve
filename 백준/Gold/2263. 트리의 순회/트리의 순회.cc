#include <iostream>
#include <algorithm>

using namespace std;

int n;
int pre[100000], in[100000], post[100000];
int pre_idx = 0;

void build(int s, int e, int s2, int e2){
	if (e - s != e2 - s2) return;
	if (s>=e || s2>=e2) return;

	for (int i=0; i<e-s; i++){
		if (in[s+i] == post[e2-1]){
			pre[pre_idx++] = post[e2-1];
			build(s, s+i, s2, s2+i);
			build(s+i+1, e, s2+i, e2-1);
			return;
		}
	}
	 
}
int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin>>n;
	for (int i=0; i<n; i++) cin>>in[i];
	for (int i=0; i<n; i++) cin>>post[i];
	
	build(0, n, 0, n);
	for (int i=0; i<n; i++) cout<<pre[i]<<" ";
	cout<<'\n';

	return 0;
}