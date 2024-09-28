#include <iostream>
#include <queue>
#define PII pair<int,int>
using namespace std;

int N,a,b;
int arr[10001];
bool visited[10001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>N;
	for (int i=1; i<=N; i++) cin>>arr[i];
	cin>>a>>b;

	queue<PII> q;
	q.push({0, a});
	visited[a] = true;
	while (!q.empty()) {
		auto [cnt, pos] = q.front();
		q.pop();

		if (pos == b) {
			cout << cnt;
			return 0;
		}

		for (int i=pos-arr[pos]; i>=1; i-=arr[pos]) {
			if (!visited[i]) {
				visited[i] = true;
				q.push({cnt+1, i});
			}
		}
		for (int i=pos+arr[pos]; i<=N; i+=arr[pos]) {
			if (!visited[i]) {
				visited[i] = true;
				q.push({cnt+1, i});
			}
		}
	}
	
	cout<<-1;
	return 0;
}