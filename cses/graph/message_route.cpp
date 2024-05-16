#include <bits/stdc++.h>
using namespace std;

#define pb push_back

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int n, m, a, b; cin >> n >> m;
	vector<vector<int>> adj(n);
	vector<int> dist(n, INT_MAX), par(n, -1);
	queue<int> q; 
	q.push(0); dist[0] = 0; par[0] = 0;
	for (int i=0;i<m;i++) {
		cin >> a >> b; a--; b--;
		adj[a].pb(b); adj[b].pb(a);
	}
	while (q.size()) {
		int cur = q.front(); q.pop();
		for (int x : adj[cur]) {
			if (dist[x] == INT_MAX) {
				dist[x] = dist[cur]+1;
				par[x] = cur;
				q.push(x);
			}
		}
	}

	if (dist[n-1] == INT_MAX) {cout << "IMPOSSIBLE\n";}
	else {
		vector<int> ans; ans.pb(n-1);
		while (ans.back()) {ans.pb(par[ans.back()]);}

		cout << ans.size() << '\n';
		reverse(ans.begin(), ans.end());
		for (int i : ans) {cout << i+1 << ' ';}
	}
}
