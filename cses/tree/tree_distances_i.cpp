#include <bits/stdc++.h>
using namespace std;

#define pb push_back

vector<vector<int>> adj;
vector<int> mx1;
vector<int> mx2;
vector<int> ans;

// max distance to a leaf
void dfs(int cur, int par) {
	for (auto x : adj[cur]) {
		if (x != par) {
			dfs(x, cur);
			if (mx1[x]+1 > mx1[cur]) {
				mx2[cur] = mx1[cur];
				mx1[cur] = mx1[x]+1;
			} else if (mx1[x]+1 > mx2[cur]) {
				mx2[cur] = mx1[x]+1;
			}
		}
	}
}

// max distance to a node outside subtree
void dfs2(int cur, int par, int path2) {
	ans[cur] = max(path2, mx1[cur]);
	for (auto x : adj[cur]) {
		if (x != par) {
			if (mx1[x]+1 == mx1[cur]) {
				dfs2(x, cur, max(mx2[cur], path2)+1);
			} else {
				dfs2(x, cur, max(mx1[cur], path2)+1);
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	int n, a, b; cin >> n;
	adj.resize(n);
	mx1.assign(n, 0);
	mx2.assign(n, 0);
	ans.resize(n, 0);
	for (int i=0;i<n-1;i++) {
		cin >> a >> b;
		adj[--a].pb(--b);
		adj[b].pb(a);
	}

	dfs(0,0);
	dfs2(0,0,0);

	for (int i=0;i<n;i++) {cout << ans[i] << '\n';}
}
