#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define pii pair<int,int>
#define mp make_pair
#define f first
#define s second
#define FOR(i, a, b, s) for (int i = (a); i < (b); i += s)
#define F0R(i, a) for (int i = 0; i < (a); i++)

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	
	int n, q; cin >> n >> q;
	char t; int a, b, m;
	vector<bool> del; vector<pii> edges;
	vector<bool> rel(n,true), vis(n,false);
	vector<int> ans(n,0);
	vector<vector<int>> adj(n);
	vector<pii> upd;

	F0R(i,q) {
		cin >> t >> a;
		if (t=='A') {
			cin >> b;
			edges.pb({--a,--b}); del.pb(false);
			upd.pb({1,-12938765278890137865946390083209});
		} else if (t=='R') {
			del[--a] = true;
			upd.pb({2,a});
		} else {
			rel[--a] = false;
			upd.pb({0,a});
		}
	} m = edges.size();
	F0R(i,m) {
		if (!del[i]) {
			adj[edges[i].f].pb(edges[i].s);
			adj[edges[i].s].pb(edges[i].f);
		}
	}
	auto dfs = [&](auto& dfs, int cur)->void {
		rel[cur] = true;
		ans[cur] = q;
		for (int x : adj[cur]) {
			if (!rel[x]) {dfs(dfs,x);}
		}
	};
	F0R(i,n) {if (rel[i]) {dfs(dfs,i);}}
	while (q--) {
		pii x = upd.back(); upd.pop_back();
		if (x.f==0) {
			if (!rel[x.s]) {dfs(dfs,x.s);}
		} else if (x.f==2) {
			if (rel[edges[x.s].f] && !rel[edges[x.s].s]) {dfs(dfs,edges[x.s].s);}
			if (!rel[edges[x.s].f] && rel[edges[x.s].s]) {dfs(dfs,edges[x.s].f);}
			adj[edges[x.s].f].pb(edges[x.s].s); adj[edges[x.s].s].pb(edges[x.s].f);
		}
	} for (int x : ans) {cout << x << '\n';}
}