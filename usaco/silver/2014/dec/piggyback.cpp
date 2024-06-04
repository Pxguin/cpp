#include <bits/stdc++.h>
using namespace std;

#define pb push_back

int main() {
	freopen("piggyback.in","r",stdin);
	freopen("piggyback.out","w",stdout);
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int b, e, p, n, m; cin >> b >> e >> p >> n >> m;
	vector<vector<int>> adj(n);
	int a1, b1;
	for (int i=0;i<m;i++) {
		cin >> a1 >> b1; a1--; b1--;
		adj[a1].pb(b1); adj[b1].pb(a1);
	}

	vector<int> sp_b(n,INT_MAX), sp_e(n,INT_MAX), sp_p(n,INT_MAX);
	auto bfs = [&](vector<int>& d, int start) {
		queue<int> q; q.push(start); d[start] = 0;
		while (q.size()) {
			int cur = q.front(); q.pop();
			for (int x : adj[cur]) {
				if (d[x] == INT_MAX) {d[x] = d[cur]+1; q.push(x);}
			}			
		}
	};
	bfs(sp_b,0); bfs(sp_e,1); bfs(sp_p,n-1);

	int ans = INT_MAX;
	for (int i=0;i<n;i++) {
		ans = min(ans, sp_b[i]*b+sp_e[i]*e+sp_p[i]*p);
	} cout << ans << '\n';
}
