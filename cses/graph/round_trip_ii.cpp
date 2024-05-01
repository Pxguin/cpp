#include <bits/stdc++.h>
using namespace std;

#define pb push_back

vector<vector<int>> adj;
vector<bool> vis, used;
vector<int> cycle;
int ok = -1;


void dfs(int cur) {
	vis[cur] = true;
	used[cur] = true;
	if (ok == -1) {cycle.pb(cur);}
	
	for (int x : adj[cur]) {
		if (!vis[x]) {dfs(x);}
		else {
			if (used[x]) {
				if (ok == -1) {ok = x;}
				// cycle
			}
		}
	}
	if (ok == -1) {cycle.pop_back();}
	used[cur] = false;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int n, m; cin >> n >> m;
	int a, b;
	adj.resize(n);
	used = vector<bool>(n); vis = vector<bool>(n);
	for (int i=0;i<m;i++) {
		cin >> a >> b; a--; b--;
		adj[a].pb(b);
	}

	for (int i=0;i<n;i++) {
		if (!vis[i]) {dfs(i);}
		if (ok+1) {break;}
	}
	if (!(ok+1)) {cout << "IMPOSSIBLE\n";}
	else {
		int flag = -1;
		for (int i=0;i<cycle.size();i++) {
			if (cycle[i] == ok) {
				flag = i;
				cout << cycle.size()-i+1 << '\n';
			}
			if (flag+1) {cout << cycle[i]+1 << ' ';}
		}
		cout << cycle[flag]+1;
	}
}
