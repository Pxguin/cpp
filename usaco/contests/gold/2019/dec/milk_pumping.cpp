#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define pll pair<ll,ll>
#define mp make_pair
#define f first
#define s second
#define ld long double

struct Edge {
	int b, c, flow;
	Edge (int b1, int c1, int f1) : b(b1), c(c1), flow(f1) {};
};

int main() {
	freopen("pump.in","r",stdin);
	freopen("pump.out","w",stdout);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int n, m; cin >> n >> m;
	int a1, b1, f1, c1;
	vector<vector<Edge>> adj(n);
	unordered_set<int> f_values;

	for (int i=0;i<m;i++) {
		cin >> a1 >> b1 >> c1 >> f1; a1--; b1--;
		adj[a1].pb(Edge(b1, c1, f1));
		adj[b1].pb(Edge(a1, c1, f1));
		f_values.insert(f1);
	}
	ld ans = 0;
	for (int i : f_values) {
		vector<ll> cost(n, LLONG_MAX);
		cost[0] = 0;
		priority_queue<pll, vector<pll>, greater<pll>> pq;
		pq.push(mp(0,0));

		while (pq.size()) {
			pll cur = pq.top(); pq.pop();
			if (cost[cur.s] != cur.f) {continue;}
			for (Edge x : adj[cur.s]) {
				if (x.flow < i) {continue;}
				if (cur.f+x.c < cost[x.b]) {
					pq.push(mp(cost[x.b] = cur.f+x.c, x.b));
				}
			}
		}
		if (cost[n-1] != LLONG_MAX) {ans = max(ans, (ld)i/cost[n-1]);}
	}
	cout << (ll)(1e6*ans) << '\n';
}
