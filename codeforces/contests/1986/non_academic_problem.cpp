#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define FOR(i, a, b, s) for (int i = (a); i < (b); i += s)
#define F0R(i, a) for (int i = 0; i < (a); i++)

vector<vector<int>> adj;
vector<bool> vis;
vector<int> low, disc;
vector<ll> nodes;
ll ans = 0;
int t; ll n;

void dfs(int cur, int par) {
	vis[cur] = true;
	low[cur] = disc[cur] = ++t;
	for (int x : adj[cur]) {
		if (x == par) {continue;}
		if (!vis[x]) {
			dfs(x,cur);
			nodes[cur] += nodes[x];
			if (disc[cur] < low[x]) {
				ans = min(ans,((nodes[x])*(nodes[x]-1)/2)+((n-nodes[x])*(n-nodes[x]-1)/2));
			}
			low[cur] = min(low[cur],low[x]);
		} else {low[cur] = min(low[cur],disc[x]);}
	} 
}

void solve() {
	int m, a, b; cin >> n >> m;
	adj.clear(); adj.resize(n);
	disc.clear(); disc.resize(n,0);
	low.clear(); low.resize(n,0);
	vis.clear(); vis.resize(n,false);
	nodes.clear(); nodes.resize(n,1);
	t = 0, ans = (ll)n*(n-1)/2;

	F0R(i,m) {
		cin >> a >> b;
		adj[--a].pb(--b); adj[b].pb(a);
	}
	dfs(0,0);
	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);

	int t; cin >> t;
	while (t--) {solve();}
}