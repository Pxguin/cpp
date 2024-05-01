#include <bits/stdc++.h>
using namespace std;

#define pb push_back

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
	adj.resize(n); vis = vector<bool>(n);
	int a, b;

	for (int i=0;i<m;i++) {
		cin >> a >> b; a--; b--;
		adj[b].pb(a);
	}

	for (int i=0;i<n;i++) {
		if (!vis[i]) {dfs(i);}
	}
	vector<int> dp(n, -1); dp[0] = 0;
	vector<int> prev(n); prev[0] = 0;
	for (int i : ts) {
		//cout << i << endl;
		int mx = -1;
		for (int j : adj[i]) {
			if (dp[j]>mx) {
				mx = dp[j];
				prev[i] = j;
			}
		}
		dp[i] = (mx+1 ? mx+1 : -1);
		if (i == 0) {dp[i] = 0;}
	}
    
	if (dp[n-1] < 0) {cout << "IMPOSSIBLE";}
	else {
		cout << dp[n-1]+1 << '\n';
		vector<int> ans;
		int x = n-1; 
		while (x != 0) {
			ans.pb(x);
			x = prev[x];
		}
		reverse(ans.begin(), ans.end());
		cout << 1 << ' ';
		for (int i : ans) {cout << i+1 << ' ';}
	}
}
