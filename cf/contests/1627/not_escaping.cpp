#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define pii pair<ll,ll>
#define mp make_pair
#define f first
#define s second
#define FOR(i, a, b, s) for (int i = (a); i < (b); i += s)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define sz(x) int((x).size())

struct Edge {
	ll to, w, floor;
	Edge(ll to1, ll w1, ll floor1) : to(to1), w(w1), floor(floor1) {};
};

void solve() {
	int n, m, k; cin >> n >> m >> k;
	ll h[n];
	F0R(i,n) {cin >> h[i];}
	ll a, b, c, d, e;
	vector<vector<Edge>> adj(2*k+2); 
	vector<vector<pii>> ends(n);
	ends[0].pb(mp(0,2*k)); ends[n-1].pb(mp(m-1,2*k+1));
	F0R(i,k) {
		cin >> a >> b >> c >> d >> e; a--; b--; c--; d--;
		adj[i*2].pb(Edge(i*2+1,-e,c));
		ends[a].pb(mp(b,i*2)); ends[c].pb(mp(d,i*2+1));
	}
	auto me = [&](int i, const pii& a1, const pii& b1) {
		ll dist = (a1.f-b1.f)*h[i];
		adj[a1.s].pb(Edge(b1.s,dist,i));
		adj[b1.s].pb(Edge(a1.s,dist,i));
	};
	F0R(i,n) {
		sort(ends[i].begin(),ends[i].end());
		FOR(j,1,sz(ends[i]),1) {
			me(i, ends[i][j], ends[i][j-1]);
		}
		ends[i].clear(); 
	}
	// dijkstra from 2*k to 2*k+1
	vector<priority_queue<pii,vector<pii>,greater<pii>>> pq(n);
	pq[0].push({0,2*k});
	vector<ll> dist(2*k+2,LLONG_MAX); dist[2*k] = 0;
	F0R(idx, n) {
		while (pq[idx].size()) {
			pii cur = pq[idx].top(); pq[idx].pop();
			if (dist[cur.s] != cur.f) {continue;}
			for (Edge x : adj[cur.s]) {
				if (dist[x.to] > cur.f+x.w) {
					pq[x.floor].push({dist[x.to]=cur.f+x.w,x.to});
				}
			}
		}
	}
	if (dist[2*k+1] == LLONG_MAX) {cout << "NO ESCAPE\n";}
	else {cout << dist[2*k+1] << '\n';}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int t; cin >> t;
	while (t--) {solve();}
}
