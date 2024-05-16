#include <bits/stdc++.h>
using namespace std;

#define pb push_back

vector<vector<int>> adj;
vector<int> ans;
bool flag = false;

void dfs(int cur, int team) {
	ans[cur] = team;
	
	for (int x : adj[cur]) {
		if (ans[x] == team) {flag = true;}
		else {
			if (ans[x] == -1) {dfs(x, !team);}
		}	
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	int n, m; cin >> n >> m;
	int a, b;

	adj.resize(n); ans.assign(n, -1);

	for (int i=0;i<m;i++) {
		cin >> a >> b; a--; b--;
		adj[a].pb(b);
		adj[b].pb(a);
	}

	for (int i=0;i<n;i++) {
		if (ans[i] == -1) {
			dfs(i, 0);
		}
	}
	if (flag) {cout << "IMPOSSIBLE";}
	else {for (int i : ans) {cout << i+1 << ' ';}}
}
