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

	int n, m, a, b; cin >> n >> m >> a >> b;
	a--; b--;
	int u,v,w;
	vector<vector<pii>> adj(n);
	F0R(i,m) {
		cin >> u >> v >> w;
		adj[--u].pb({--v,w});
		adj[v].pb({u,w});
	}
	int k; cin >> k;
	vector<int> path(k);
	F0R(i,k) {cin >> path[i]; path[i]--;}

	// sp tree
	vector<ll> dist_a(n,LLONG_MAX), dist_b(n,LLONG_MAX);
	vector<int> par_a(n,-1),par_b(n,-1);
	vector<int> rank(n,-1); 
	F0R(i,k) {rank[path[i]]=i;}
	vector<vector<ll>> add(k),del(k);
	auto edge = [&](int x, int cur, int z)->bool {return (rank[x]!=-1 && (0<=rank[x]+z && rank[x]+z<k) && cur==path[rank[x]+z]);};
	auto dijkstra = [&](int& src, vector<ll>& dist, vector<int>& par, int z) {
		priority_queue<T,vector<T>,greater<T>> pq; // dist, rank, node
		pq.push({dist[src]=0,{rank[src]*z,src}}); // z=1 when starting from back
		F0R(i,k) {par[path[i]]=path[i];}
		while (pq.size()) {
			auto [d,xz] = pq.top(); pq.pop();
			auto [rnk,cur] = xz;
			if (dist[cur]!=d || rnk!=rank[par[cur]]*z) {continue;}

			for (pii x : adj[cur]) {
				if (d+x.s<dist[x.f]) {
					if (!edge(x.f,cur,z)) {par[x.f]=par[cur];}
					else if (edge(x.f,cur,z)) {par[x.f]=x.f;}
					pq.push({dist[x.f]=d+x.s,{rank[par[x.f]]*z,x.f}});
				} /*else if (d+x.s==dist[x.f]) {
					if (rnk*z > rank[par[x.f]]*z && !edge(x.f,cur,z)) {
						pq.push({dist[x.f],{rank[par[x.f]=par[cur]]*z,x.f}});
					}
				}*/
			}
		}
	};
	dijkstra(a,dist_a,par_a,-1);
	dijkstra(b,dist_b,par_b,1);
	
	F0R(i,n) {
		for (pii x : adj[i]) {
			if (edge(i,x.f,1) || edge(i,x.f,-1)) {continue;}
			int l = rank[par_a[i]], r = rank[par_b[x.f]]-1;
			if (l<=r) {
				add[l].pb(dist_a[i]+x.s+dist_b[x.f]); // i: par_a[] means anything strictly after the edge ending there
				del[r].pb(dist_a[i]+x.s+dist_b[x.f]); // j: par_b[] means anything strictly before the edge starting there
			}
		}
	}
	multiset<ll> cand;
	F0R(i,k-1) {
		for (ll x : add[i]) {cand.insert(x);}
		cout << (cand.size() ? *cand.begin() : -1) << '\n';
		for (ll x : del[i]) {cand.erase(cand.find(x));}
	}
}