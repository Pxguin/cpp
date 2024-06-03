#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define mp make_pair
#define pii pair<int,int>
#define f first
#define s second

int main() {
	freopen("dining.in","r",stdin);
	freopen("dining.out","w",stdout);
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int n, m, k; cin >> n >> m >> k;
	int a, b, t;
	vector<vector<pii>> adj(n);
	vector<int> food(n,0);
	for (int i=0;i<m;i++) {
		cin >> a >> b >> t; 
		adj[--a].pb(mp(--b,t));
		adj[b].pb(mp(a,t));
	}
	for (int i=0;i<k;i++) {cin >> a >> b; a--; food[a]=max(food[a],b);}

	priority_queue<pii,vector<pii>,greater<pii>> pq; pq.push({0,n-1});
	vector<int> dist(n,INT_MAX); dist[n-1]=0;

	auto dijkstra = [&](vector<int>& d) {
		while (pq.size()) {
			pii cur = pq.top(); pq.pop();
			if (cur.f != d[cur.s]) {continue;}
			for (pii x : adj[cur.s]) {
				if (d[x.f] > d[cur.s]+x.s) {
					pq.push({d[x.f]=d[cur.s]+x.s,x.f});
				}
			}
		}
	};
	dijkstra(dist);
	
	vector<int> dist2(n,INT_MAX);
	for (int i=0;i<n;i++) {
		if (food[i]) {
			dist2[i] = dist[i]-food[i]; 
			pq.push(mp(dist2[i],i));
		}
	}
	dijkstra(dist2);
	for (int i=0;i<n-1;i++) {cout << (dist2[i]<=dist[i]) << '\n';}
}
