#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define pii pair<ll,ll>
#define mp make_pair
#define f first
#define s second
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define F0R(i, a) for (int i = 0; i < (a); i++)

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	
	int n, m; cin >> n >> m;
	int s, t, u, v; cin >> s >> t >> u >> v;
	int a, b, c;
	vector<vector<pii>> adj(n);

	F0R(i,m) {
		cin >> a >> b >> c;
		adj[--a].pb({--b,c}); adj[b].pb({a,c});
	}
	vector<ll> dist_s(n,LLONG_MAX), dist_u(n,LLONG_MAX),dist_v(n,LLONG_MAX);
	dist_s[--s] = dist_u[--u] = dist_v[--v] = 0; t--;

	auto dijkstra = [&](vector<ll>& ret, int start)->void {
		priority_queue<pii,vector<pii>,greater<pii>> pq;
		pq.push({0,start});
		while (pq.size()) {
			pii cur = pq.top(); pq.pop();
			if (cur.f > ret[cur.s]) {continue;}
			for (pii x : adj[cur.s]) {
				if (cur.f+x.s < ret[x.f]) {
					pq.push({ret[x.f]=cur.f+x.s,x.f});
				}
			}
		}
	};
	dijkstra(dist_s,s); dijkstra(dist_u,u); dijkstra(dist_v,v);
	ll ans = dist_u[v];

	vector<pii> ret(n+1,{-1,-1});
	auto dfs = [&](auto&& dfs, int cur)->void {
		ret[cur] = {dist_u[cur],dist_v[cur]};
		for (pii x : adj[cur]) {
			if (dist_s[x.f] == dist_s[cur]-x.s) {
				if (ret[x.f] == ret[n]) {dfs(dfs,x.f);}
				ret[cur].f = min(ret[cur].f,ret[x.f].f);
				ret[cur].s = min(ret[cur].s,ret[x.f].s);
			}
		}
		ans = min(ans,dist_u[cur]+ret[cur].s);
		ans = min(ans,dist_v[cur]+ret[cur].f);
	};
	dfs(dfs,t); cout << ans << '\n';
}