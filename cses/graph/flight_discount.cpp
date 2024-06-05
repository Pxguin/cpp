#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<ll,ll>
#define mp make_pair
#define f first
#define s second
#define pb push_back

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, m; cin >> n >> m;
	int a, b; ll t;
	vector<vector<pii>> adj(n);
	for (int i=0;i<m;i++) {
		cin >> a >> b >> t;
		adj[--a].pb(mp(--b,t));
	}

	using T = pair<ll,pii>;
	priority_queue<T,vector<T>,greater<T>> pq; pq.push({0,{0,0}});
	vector<vector<ll>> dist(n,vector<ll>(2,LLONG_MAX)); dist[0][0] = 0;

	while (pq.size()) {
		T cur = pq.top(); pq.pop();
		if (dist[cur.s.s][cur.s.f] != cur.f) {continue;}
		for (pii x : adj[cur.s.s]) {
			// use discount
			if (!cur.s.f) {
				if (dist[x.f][1]>cur.f+x.s/2) {
					pq.push({dist[x.f][1]=cur.f+x.s/2,{1,x.f}});
				}
			}
			// dont use
			if (dist[x.f][cur.s.f]>cur.f+x.s) {
				pq.push({dist[x.f][cur.s.f]=cur.f+x.s,{cur.s.f,x.f}});
			}
		}
	}
	cout << dist[n-1][1] << '\n';
}
