#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long

vector<vector<int>> adj;
vector<ll> sum;
vector<ll> nodes;
vector<ll> ans;
ll n;

void dfs(int cur, int par) {
	for (int x : adj[cur]) {
		if (x != par) {
			dfs(x, cur);
			nodes[cur] += nodes[x]+1;
			sum[cur] += sum[x];
		}
	}
	sum[cur] += nodes[cur];
}

void dfs2(int cur, int par, ll sum2 = 0) {
	ans[cur] = sum[cur] + sum2;
	for (int x : adj[cur]) {
		if (x != par) {
			dfs2(x, cur, sum2+(sum[cur]-sum[x]-nodes[x]-1)+(n-nodes[x]-1));
		}
	}
}
// two sums
// everything inside subtree, everything outside subtree
// number of nodes in each subtree is h[x]
// f[x] = f[c]+h[x]
// g[c] = g[x]+(n-h[x])

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	cin >> n;
	int a, b;
	sum.assign(n, 0);
	adj.resize(n);
	nodes.resize(n, 0);
	ans.resize(n, 0);
	for (int i=0;i<n-1;i++) {
		cin >> a >> b; a--; b--;
		adj[a].pb(b);
		adj[b].pb(a);
	}

	dfs(0,0);
	dfs2(0,0);
	for (ll i : ans) {cout << i << endl;}
}
