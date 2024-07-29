#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
using namespace std;

bool cmp(pair<string, int>& a, pair<string, int>& b) {
    if (a.second != b.second) return a.second > b.second;
    if (a.first.size() != b.first.size()) return a.first.size() > b.first.size();
    return a.first < b.first;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    map<string, int> MAP;
    int n,m;
    string s;
    cin>>n>>m;

    for (int i=0; i<n; i++) {
        cin>>s;
        if (s.size() >=m) MAP[s]++;
    }

    vector<pair<string, int>> v(MAP.begin(), MAP.end());
    sort(v.begin(), v.end(), cmp);

    for (pair<string, int>& p : v) {
        cout<<p.first<<'\n';
    }

 
    return 0;
}