#include <bits/stdc++.h>
using namespace std;

#define pii pair<int,int>
#define f first
#define s second
#define pb push_back

vector<vector<int>> adj(2e5), col(2e5);
vector<int> dist(2e5);
vector<bool> vis2(2e5);

void solve() {
	int n, m; cin >> n >> m;
	int a, b, c;
	unordered_set<int> colors;
	for (int i=0;i<m;i++) {
		cin >> a >> b >> c;
		adj[--a].pb(--c);
		adj[--b].pb(c);
		col[c].pb(a); col[c].pb(b);
		colors.insert(c);
	}
	for (int i : colors) {vis2[i] = false;}
	for (int i=0;i<n;i++) {dist[i] = INT_MAX;} 
	
	cin >> b >> c; b--; c--; dist[b] = 0;

	queue<pii> q; q.push({0,b});
	while (q.size()) {
		pii cur = q.front(); q.pop();
		if (dist[cur.s] != cur.f) {continue;}
		for (int x : adj[cur.s]) {
			if (!vis2[x]) {
				vis2[x] = true;
				for (int y : col[x]) {
					if (dist[cur.s]+1 < dist[y]) {
						dist[y] = dist[cur.s]+1;
						q.push({dist[y],y});
					}
				}
			}
		}
	}
	cout << dist[c] << '\n';

	for (int i=0;i<n;i++) {adj[i].clear();}
	for (int i : colors) {col[i].clear();}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--) {solve();}
}
