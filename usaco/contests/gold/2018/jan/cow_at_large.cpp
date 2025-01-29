#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define FOR(i, a, b, s) for (int i = (a); i < (b); i += s)
#define F0R(i, a) for (int i = 0; i < (a); i++)

int n, ans = 0;
vector<vector<int>> adj; vector<int> dist, dist2;

void dfs(int cur, int par) {
	for (int x : adj[cur]) {
		if (x != par) {
			dist[x] = dist[cur]+1;
			dfs(x,cur);
			dist2[cur] = min(dist2[cur],dist2[x]+1);
		}
	} if (adj[cur].size()==1) {dist2[cur] = 0;}
}

void dfs2(int cur, int par) {
	if (dist[cur] >= dist2[cur]) {ans++;}
	else {
		for (int x : adj[cur]) {if (x != par) {dfs2(x,cur);}}
	}
}

int main() {
	freopen("atlarge.in","r",stdin);
	freopen("atlarge.out","w",stdout);
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	int k, a, b; cin >> n >> k;
	adj.resize(n); dist2.assign(n,INT_MAX); dist.assign(n,INT_MAX);
	F0R(i,n-1) {
		cin >> a >> b;
		adj[--a].pb(--b); adj[b].pb(a);
	}

	dist[--k] = 0;
	dfs(k,k);
	dfs2(k,k);
	cout << ans << '\n';
} 	