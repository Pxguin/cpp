// favorite problem, possibly

#include <bits/stdc++.h>
using namespace std;

#define pb push_back

vector<int> path, cur_path;
int ans = 0, dist = 0, x = 0;
vector<vector<int>> graph;

void dfs(int cur, int par) {
	cur_path.pb(cur);
	for (int adj : graph[cur]) {
		if (adj != par) {
			dist++;
			dfs(adj, cur);
		}
	}
	if (dist > ans) {x = cur; ans = dist; path = cur_path;}
	dist--; cur_path.pop_back();
}

void solve() {
	ans = 0; dist = 0; x = 0;
	path.clear(); cur_path.clear();
	int n; cin >> n;
	int a, b;
	graph.clear(); graph.resize(n);
	for (int i=0;i<n-1;i++) {
		cin >> a >> b; a--; b--;
		graph[a].pb(b); graph[b].pb(a);
	}
	// calc diameter
	dfs(0, 0);
	ans = 0; dist = 0;
	path.clear(); cur_path.clear();
	dfs(x, x);
	if (path.empty()) {path.pb(0);}
	int sz = path.size();
	if (sz%2) {
		cout << sz/2+1 << '\n';
		for (int i=sz/2;i>=0;i--) {
			cout << path[sz/2]+1 << ' ' << i << '\n';
		}
	} else {
		int ops = (sz+3)/4*2;
		cout << ops << '\n';
		for (int i=sz/2-1;i>=0;i-=2) {
			cout << path[sz/2]+1 << ' ' << i << '\n';
			cout << path[sz/2-1]+1 << ' ' << i << '\n';
		}
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int t; cin >> t;
	while (t--) {solve();}
}
