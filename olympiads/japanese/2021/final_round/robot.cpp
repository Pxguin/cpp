#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define pii pair<ll,ll>
#define f first
#define s second
#define F0R(i, a) for (int i = 0; i < (a); i++)

using T = pair<ll,pii>;

int main() {
	ios::sync_with_stdio(false); cin.tie(0);

	int n, m, a, b, c, p; cin >> n >> m;
	vector<map<int,ll>> trsn(n), sum(n);
	vector<ll> dist(n,LLONG_MAX);
	vector<map<int,vector<pii>>> adj(n);
	F0R(i,m) {
		cin >> a >> b >> c >> p; a--; b--;
		adj[a][c].pb({b,p}); // store adjacency list for each color
		adj[b][c].pb({a,p});
		trsn[a][c] = trsn[b][c] = LLONG_MAX;
		sum[a][c] += p; sum[b][c] += p;
	} 
	priority_queue<T,vector<T>,greater<T>> pq; // dist, node, color [1,m], 0 for unspecified color
	dist[0] = 0; 
	pq.push({0,{0,0}});

	while (pq.size()) {
		auto[d,z] = pq.top(); pq.pop();
		auto[cur,t] = z;

		if ((!t && dist[cur]!=d) || (t && trsn[cur][t]!=d)) {continue;}

		if (!t) { // push to (self, complement), and transition
			for (auto z1 : adj[cur]) {
				for (auto z : z1.s) {
					auto[x,p] = z; c = z1.f;
					if (d+p<dist[x]) {pq.push({dist[x]=d+p,{x,0}});} // self
					if (d+sum[cur][c]-p<dist[x]) {pq.push({dist[x]=d+sum[cur][c]-p,{x,0}});} // complement
					if (d<trsn[x][c]) {pq.push({trsn[x][c]=d,{x,c}});} // transition
				}		
			}
		} else { // push to complement
			for (auto z : adj[cur][t]) {
				auto[x,p] = z; c = t;
				if (sum[cur][c]+d-p<dist[x]) {pq.push({dist[x]=sum[cur][c]+d-p,{x,0}});}
			}
		}
	} cout << (dist[n-1]==LLONG_MAX ? -1 : dist[n-1]) << '\n';
}