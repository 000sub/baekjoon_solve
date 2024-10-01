#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#define PII pair<int,int>
using namespace std;

constexpr int dx[] = {0,-1,0,1};
constexpr int dy[] = {1,0,-1,0};

int T, N;
vector<int> adjs[102];
bool visited[102];
PII stores[102];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin>>T;

	while (T--) {
		cin>>N;
		for (int i=0; i<=N+1; i++) {
			cin>>stores[i].first>>stores[i].second;
			for (int j=0; j<i; j++) {
				if (abs(stores[i].first - stores[j].first) + abs(stores[i].second - stores[j].second) <= 1000) {
					adjs[i].push_back(j);
					adjs[j].push_back(i);
				}
			}
		}

		queue<int> q;
		bool found = false;
		q.push(0);
		visited[0] = true;
		while (!q.empty()) {
			int cur = q.front();
			q.pop();

			if (cur == N+1) {
				found = true;
				break;
			}

			for (int next : adjs[cur]) {
				if (!visited[next]) {
					q.push(next);
					visited[next] = true;
				}
			}
		}

		found ? cout<<"happy" : cout<<"sad";
		cout<<'\n';

		for (int i=0; i<=N+1; i++) adjs[i].clear();
		memset(visited, false, sizeof(visited));
	}
    
    return 0;
}