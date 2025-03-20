#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long

vector<vector<int>> adj;
vector<int> vis;
ll c1 = 0, c2 = 0;
bool flag = false;

void dfs(int cur, int team) {
	vis[cur] = team;
	if (team) {c2++;} else {c1++;}
	for (int x : adj[cur]) {
		if (vis[x] == -1) {dfs(x, !team);}
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	int n; cin >> n;
	int a, b;
	adj.resize(n); vis.assign(n, -1);
	for (int i=0;i<n-1;i++) {
		cin >> a >> b; a--; b--;
		adj[a].pb(b); adj[b].pb(a);
	}

	dfs(0,0);
	
	cout << (c1*c2)-n+1 << '\n';
}
