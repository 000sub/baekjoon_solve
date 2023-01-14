#include <iostream>
#include <algorithm>
#include <cstring>

#define MAX 100001
using namespace std;

int arr[MAX], cnt;
bool visited[MAX], finished[MAX];

void dfs(int num){
	int choice = arr[num];
	visited[num] = true;
	if (visited[choice]){
		if (!finished[choice]){
			for (int tmp = choice; tmp!=num; tmp = arr[tmp]){
				cnt++;
			}
			cnt++;
		}
	}
	else {
		dfs(choice);
	}
	
	finished[num] = true;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int T, n;
	
	cin>>T;
	
	for (int tc=0; tc<T; tc++){
		cin>>n;
		
		for (int i=1;i<=n;i++) cin>>arr[i];
		
		fill(visited, visited+MAX, false);
		fill(finished, finished+MAX, false);
		
		cnt=0;
		for (int i=1;i<=n;i++){
			dfs(i);
		}
		
		cout<<n-cnt<<'\n';
		
	}

	return 0;
}