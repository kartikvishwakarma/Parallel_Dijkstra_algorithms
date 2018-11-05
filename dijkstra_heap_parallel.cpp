/*
	implementation of parallel heap based 
	dijsktra algorithm for single source 
	shortest path.
	On dataset "data.txt"

	it tooks almost 6sec with each node degree 100 
*/

#include <iostream>
#include <algorithm>
#include <queue>
#include <map>
#include <unordered_set>

#include <climits>
#include <vector>
#include <utility>
#include <omp.h>

#define inf INT_MAX

using namespace std;

typedef pair<int, int> pi;

int main(){
	int n;
	int s;
	int d;
	float w;
	int id;
	int src=1;//7590;
	int i, start, end, N, nth;
	cin >> n;
	int count=0;
	//cout << n << '\n';
	map<int, vector<pi> > graph;
	map<int, int> dist;
	unordered_set<int> S;

	for(int i=0; i<n; i++){
		cin >> id >> s >> d >> w;
		//cin >> s >> d >> w;
		//cout << s << ' ' << d << ' ' << w << '\n';
		graph[s].push_back(make_pair(d,w));
		graph[d].push_back(make_pair(s,w));
		S.insert(s);
		S.insert(d);
	}

	priority_queue <pi , vector<pi>, greater<pi> > Q;

	for(auto l : S)
		dist[l] = inf;
	S.clear();

	dist[src] = 0;

	Q.push(make_pair(0, src));


	while(!Q.empty()){
		s = Q.top().second;
		w = Q.top().first;

		Q.pop();
		//cout << s << '\n';
		N = graph[s].size();
		//omp_set_num_threads(8);
		
			#pragma omp parallel for num_threads(8)
			for(int i=0; i<N; i++){
				pi p = graph[s][i];
				if(dist[p.first] > dist[s] + p.second){
					dist[p.first] = dist[s] + p.second;
					//cout << p.first << ' ';
					count++;
					#pragma omp critical
					Q.push(make_pair(dist[p.first], p.first));
				}
			//}
		}
		//cout << '\n';
	}

	for (auto &k : dist)
		cout << k.first << ' ' << k.second << '\n';
	cout << '\n';

	cout << count << " !!!\n";
	return 0;
}