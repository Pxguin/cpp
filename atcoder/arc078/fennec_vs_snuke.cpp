#include <bits/stdc++.h>
using namespace std;

#define pb push_back

vector<vector<int>> adj;
vector<int> path;
vector<bool> vis;
vector<int> subtree;
bool found = false;
int n;

void dfs(int cur) {
	if (!found) {path.pb(cur);}
	vis[cur] = true;
	if (cur == n-1) {found = true;}

	for (int x : adj[cur]) {
		if (!vis[x]) {
			dfs(x);
			subtree[cur] += subtree[x];
		}
	}

	if (!found) {path.pop_back();}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	cin >> n;
	adj.resize(n); vis.assign(n, false); subtree.assign(n, 1);
	int a, b;
	for (int i=0;i<n-1;i++) {
		cin >> a >> b; a--; b--;
		adj[a].pb(b);
		adj[b].pb(a);
	}

	dfs(0);
	int fennec = 0, snuke = 0;

	snuke = subtree[path[(path.size()+1)/2]];
	fennec = n - snuke;

	cout << ((fennec > snuke) ? "Fennec" : "Snuke");
}
