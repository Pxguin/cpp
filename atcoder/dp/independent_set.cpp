#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mp make_pair
#define pii pair<ll,ll>
#define f first
#define s second
#define pb push_back
#define FOR(i, a, b, s) for (int i = (a); i < (b); i += s)
#define F0R(i, a) for (int i = 0; i < (a); i++)

vector<vector<int>> adj;
vector<bool> vis;
vector<pii> dp;
ll mod = 1e9+7;

void dfs(int cur) {
	vis[cur] = true;
	for (int x : adj[cur]) {
		if (!vis[x]) {
			dfs(x);
			dp[cur].f = (dp[cur].f*(dp[x].f+dp[x].s))%mod;
			dp[cur].s = (dp[cur].s*dp[x].f)%mod;
		}
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	int n, a, b; cin >> n;
	adj.resize(n);
	vis.assign(n,false);
	dp.assign(n,mp(1,1));
	F0R(i,n-1) {
		cin >> a >> b;
		adj[--a].pb(--b);
		adj[b].pb(a);
	} dfs(0);
	cout << (dp[0].f+dp[0].s)%mod << '\n';
}