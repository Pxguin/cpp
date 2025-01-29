#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define pii pair<int,int>
#define f first
#define s second
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define v vector

int n, b;
v<v<int>> adj;
v<pii> r, c, par;
int m, flag;

void dfs(int cur) {
	par[cur] = {max(0,r[cur].f-m),r[cur].s+m};
	c[cur] = r[cur];

	for (int x : adj[cur]) {
		dfs(x);
		c[cur] = {max(c[cur].f,par[x].f),min(c[cur].s,par[x].s)}; // range for current node such that subtree is ok
		par[cur] = {max(par[cur].f,par[x].f),min(par[cur].s,par[x].s)}; // range for any ancestor such that this subtree is ok
	}
	flag |= (c[cur].f>c[cur].s); // make sure the range for this node is nonempty
}

void reversedfs(int cur) {
	for (int x : adj[cur]) {
		par[x].f = max(par[cur].f,c[x].f); // update max
		reversedfs(x);
	}
}

void solve() {
	cin >> n;
	adj.clear(); adj.resize(n);
	F0R(i,n-1) {
		int p; cin >> p;
		adj[--p].pb(i+1);
	}
	r.resize(n); c = r; par = r;
	F0R(i,n) {cin >> r[i].f >> r[i].s;}

	int lo = 0, hi = 1e9, ans; m = (lo+hi)/2;
	while (lo <= hi) { // binary search and dfs to calc ranges
		flag = 0; dfs(0);
		if (!flag) {ans = m; hi = m-1;}
		else {lo = m+1;}
		m = (lo+hi)/2;
	}
	cout << ans << '\n'; // b = 0 solved
	if (b) {
		m = ans; // re-get the ranges for the optimal answer
		dfs(0);
		par[0] = c[0]; // calc strictest left bound, maximum of (c_j-m) for all ancestors j (rewrite par array...)
		reversedfs(0);
		cout << c[0].f;
		F0R(i,n-1) {cout << ' ' << max(par[i+1].f-m,c[i+1].f);}
		cout << '\n';
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	
	int t; cin >> t >> b;
	while (t--) {solve();}
}