#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define pll pair<ll,ll>
#define mp make_pair
#define f first
#define s second

struct Edge {
	int b, w;
	Edge(int b1, ll w1) : b(b1), w(w1) {};
};

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int n, m; cin >> n >> m;
	int a1, b1; ll w1;
	vector<vector<Edge>> adj(n);
	
	for (int i=0;i<m;i++) {
		cin >> a1 >> b1 >> w1; a1--; b1--;
		adj[a1].pb(Edge(b1, w1));
		adj[b1].pb(Edge(a1, w1));
	}

	vector<ll> dist(n, LLONG_MAX);
	priority_queue<pll, vector<pll>, greater<>> pq;
	dist[0] = 0; pq.push(mp(0,0));
	vector<int> par(n, -1);

	while (pq.size()) {
		pll cur = pq.top(); pq.pop();
		if (dist[cur.s] != cur.f) {continue;}
		for (Edge x : adj[cur.s]) {
			if (dist[x.b] > cur.f+x.w) {
				pq.push(mp(dist[x.b]=cur.f+x.w, x.b));
				par[x.b] = cur.s;
			}
		}
	}
	if (dist[n-1] == LLONG_MAX) {cout << -1 << '\n';}
	else {
		vector<int> ans; ans.pb(n-1);
		while (par[ans.back()] != -1) {ans.pb(par[ans.back()]);}
		while (ans.size()) {cout << ans.back()+1 << ' '; ans.pop_back();}
	}
}
