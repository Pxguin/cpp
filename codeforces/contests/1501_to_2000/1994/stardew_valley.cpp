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

void solve() {
	int n, m, a, b, c; cin >> n >> m;
	vector<vector<pii>> adj(n);
	vector<vector<pii>> opt(n);
	vector<int> deg(n,0), deg_opt(n,0);
	vector<bool> del(m,false);
	vector<bool> vis(n,false);
	F0R(i,m) {
		cin >> a >> b >> c;
		adj[--a].pb({--b,i}); adj[b].pb({a,i});
		if (!c) {
			opt[a].pb({b,i}); opt[b].pb({a,i});
			deg_opt[a]^=1; deg_opt[b]^=1;
		} else {deg[a]^=1; deg[b]^=1;}
	}
	auto dfs = [&](auto dfs, int cur, int par)->void {
		vis[cur] = true;
		for (pii x : opt[cur]) {
			if (vis[x.f]) {continue;}
			dfs(dfs,x.f,cur);
			if (deg_opt[x.f]^deg[x.f]) {
				del[x.s] = true;
				deg_opt[x.f]^=1; deg_opt[cur]^=1;
			}
		}
	};
	F0R(i,n) {
		if (!vis[i]) {
			dfs(dfs,i,i);
			if (deg[i]^deg_opt[i]) {cout << "NO\n"; return;}
		}
	} vector<int> ans;
	auto euler = [&](auto euler, int cur)->void {
		while (adj[cur].size()) {
			pii x = adj[cur].back();
			adj[cur].pop_back();
			if (del[x.s]) {continue;}
			del[x.s] = true;
			euler(euler,x.f);
		} ans.pb(cur);
	};
	euler(euler,0);
	cout << "YES\n" << ans.size()-1 << '\n';
	for (int i : ans) {cout << i+1 << ' ';} cout << '\n';
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);

	int t; cin >> t;
	while (t--) {solve();}
}