#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#define PII pair<int,int>

using namespace std;
typedef long long ll;

vector<int> graph[500001];
int n, a, b;
int cnt = 0;
bool visited[500001];

void DFS(int x, int depth) {
	visited[x] = true;
	
	bool isLeaf = true;
	for (int next : graph[x]) {
		if (!visited[next]) {
			DFS(next, depth+1);
			isLeaf = false;
		}
	}
	if (isLeaf) cnt += depth;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	
	cin >> n;
	for (int i = 0; i < n-1; i++) {
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	DFS(1, 0);

	cnt % 2 ? cout << "Yes" : cout << "No";

	return 0;
}