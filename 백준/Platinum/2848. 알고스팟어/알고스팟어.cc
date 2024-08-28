#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
#include <unordered_set>

#define PII pair<int,int>
#define PIII pair<int,PII>

using namespace std;
typedef long long ll;

int N;
int A[26], indegree[26];
unordered_set<int> used;
vector<int> ans;
vector<int> adj[26];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	string s1, s2;
	cin >> N >> s1;

    if (N == 1) {
        for (char c : s1) {
            if (!used.count(c-'a')) {
                used.insert(c-'a');
                ans.push_back(c - 'a');
            }
        }
        for (int i : ans) cout << (char)(i+'a');
        return 0;
    }
    
	for (int i = 0; i < N - 1; i++) {
		cin >> s2;
        int len = s1.size() < s2.size() ? s1.size() : s2.size();
        bool compared = false;
		for (int j = 0; j < 10; j++) {
            if (j < s1.size()) used.insert(s1[j] - 'a');
            if (j < s2.size()) used.insert(s2[j] - 'a');
			if (j < len && s1[j] != s2[j] && !compared) {
				adj[s1[j] - 'a'].push_back(s2[j] - 'a');
				indegree[s2[j] - 'a']++;
                compared = true;
			}

            if (j>=len && !compared && s1.size() > s2.size()) {
                cout << "!";
                return 0;
            }
		}
		s1 = s2;
	}

	queue<int> q;
	for (int i = 0; i < 26; i++) if (indegree[i] == 0 && used.count(i)) ans.push_back(i),q.push(i);
	bool flag = false;

    for (int i=0; i<used.size(); i++) {
        if (q.empty()) {
            cout << "!";
            return 0;
        }

        if (q.size() >= 2) {
            flag = true;
        }

        int cur = q.front();
        q.pop();

        for (int next : adj[cur]) {
            if (--indegree[next] == 0) {
                ans.push_back(next); 
                q.push(next);
            }
        }
    }

    if (flag) {
        cout << "?";
        return 0;
    }

    for (int i : ans) {
        cout << (char)('a' + i);
    }
	
	return 0;
}