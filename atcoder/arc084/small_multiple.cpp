#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	int k; cin >> k;
	deque<int> q; q.push_front(1);
	vector<int> dist(k,INT_MAX); dist[1] = 1;
	while (q.size()) {
		int cur = q.front(); q.pop_front();
		if (dist[10*cur%k]>dist[cur]) {dist[10*cur%k]=dist[cur]; q.push_front(10*cur%k);}
		if (dist[(cur+1)%k]==INT_MAX) {dist[(cur+1)%k]=dist[cur]+1; q.push_back((cur+1)%k);}
	} cout << dist[0] << '\n';
}