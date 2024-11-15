#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define v vector

v<v<int>> adj;
v<int> deg;
ll ans = 0;
ll dfs(int cur, int par) {
	ll cnt = 0;
	v<ll> to;
	for (int x : adj[cur]) {
		if (x!=par) {
			to.pb(dfs(x,cur));
			if (deg[x]==2&&deg[cur]==3) {to[to.size()-1]++;} // make new path if child has degree 2
			cnt += to.back();
		}
	}
	ll ret = cnt; // num paths starting here and ending on a deg 2 node, with all other nodes on path being deg 3
	if (deg[cur]==2) {ans += cnt;} // line case
	else if (deg[cur]==3) { // wraparound subtree case
		for (ll x : to) {ans += x*(cnt-=x);}
	} 
	if (deg[cur]!=3) {ret=0;} // all paths terminate if degree!=3
	
	return ret;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);

	int n, a, b; cin >> n;
	adj.resize(n); deg.assign(n,0);
	F0R(i,n-1) {
		cin >> a >> b;
		adj[--a].pb(--b);
		adj[b].pb(a);
		deg[a]++; deg[b]++;
	}
	dfs(0,0);
	cout << ans << '\n';
}