#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <vector>
#include <cmath>

#define PII pair<double, double>
using namespace std;

const double INF = 1000000.0;
int N;
double dist[102];

vector<PII> v;
PII s, e;
inline double get_dist(int s, int e){
	double x = fabs(v[e].first - v[s].first);
	double y = fabs(v[e].second - v[s].second);
	return hypot(x,y);
}

void dijkstra(){
	priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>>> pq;
	
	for (int i=0; i<=N+1; i++){
		dist[i] = INF;
	}
	
	dist[0] = 0.0;
	pq.push(make_pair(dist[0], 0));
	
	while (!pq.empty()){
		double cost = pq.top().first;
		int idx = pq.top().second;
		pq.pop();
		
		if (dist[idx] < cost) continue;
		
		for (int i=0; i<=N+1; i++){
			if (idx == i) continue;
			
			double curdist = get_dist(idx, i);
			double curcost = INF;
			
			curcost = (idx==0) ? curdist / 5.0 : min(curdist / 5.0, fabs(curdist - 50.0) / 5 + 2);
			
			if (dist[i] > curcost + cost){
				dist[i] = curcost + cost;
				pq.push(make_pair(dist[i], i));
			}
		}
	}
	
	
	
	
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>s.first>>s.second>>e.first>>e.second;
	cin>>N;
	
	v.push_back(s);
	double a,b;
	for (int i=0; i<N; i++){
		cin>>a>>b;
		v.emplace_back(a,b);
	}
	v.push_back(e);
	
	dijkstra();
	cout<<dist[N+1]<<'\n';

	return 0;
}