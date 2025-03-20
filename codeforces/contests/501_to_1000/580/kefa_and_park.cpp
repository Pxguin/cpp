#include <bits/stdc++.h>
using namespace std;

#define pb push_back

#define F0R(i, a) for (int i = 0; i < (a); i++)

int n, m;
vector<int> a;
vector<vector<int>> adj;
int ans = 0;

void dfs(int cur, int cnt, int par) {
	int nxt = (a[cur] ? cnt+1 : 0);
	if (nxt<=m && adj[cur].size()==1 && cur) {ans++;}
	else if (nxt>m) {return;}
	for (int x : adj[cur]) {
		if (x != par) {dfs(x,nxt,cur);}
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	
	int u, v; cin >> n >> m;
	a.resize(n);
	adj.resize(n);
	F0R(i,n) {cin >> a[i];}
	F0R(i,n-1) {
		cin >> u >> v;
		adj[--u].pb(--v);
		adj[v].pb(u);
	}

	dfs(0,0,0);
	cout << ans << '\n';
}