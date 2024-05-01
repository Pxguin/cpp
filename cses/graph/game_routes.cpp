#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

ll MOD = 1e9+7;

vector<vector<int>> adj;
vector<bool> vis;
vector<int> ts;

void dfs(int cur) {
	vis[cur] = true;
	for (int x : adj[cur]) {
		if (!vis[x]) {dfs(x);}
	}
	ts.pb(cur);
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int n, m; cin >> n >> m;
	adj.resize(n);
	vis = vector<bool>(n);
	int a, b;
	for (int i=0;i<m;i++) {
		cin >> a >> b; a--; b--;
		adj[a].pb(b);
	}

	for (int i=0;i<n;i++) {
		if (!vis[i]) {dfs(i);}
	}
	reverse(ts.begin(), ts.end());

	vector<int> dp(n, 0);
	dp[0] = 1;
	for (int i : ts) {
		for (int j : adj[i]) {
			dp[j] = (dp[i]+dp[j]) % MOD;
		}
	}
	cout << dp[n-1] << '\n';
}
