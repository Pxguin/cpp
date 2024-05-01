#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define pii pair<int,int>
#define pb push_back
#define f first
#define s second

vector<vector<int>> adj;
vector<bool> vis;
vector<int> ts;
bool flag = false;

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
	int a, b;
	adj.resize(n); vis.assign(n, false);
	for (int i=0;i<m;i++) {
		cin >> a >> b; a--; b--;
		adj[b].pb(a);
	}
	for (int i=0;i<n;i++) {
		if (!vis[i]) {dfs(i);}
	}

	int idx[n];
	for (int i=0;i<n;i++) {
		idx[ts[i]] = i;
	}
	for (int i=0;i<n;i++) {
		for (int j : adj[i]) {
			if (idx[j] > idx[i]) {flag = true;}
		}
	}

	if (flag) {cout << "IMPOSSIBLE\n";}
	else {for (int i : ts) {cout << i+1 << ' ';}}
}
