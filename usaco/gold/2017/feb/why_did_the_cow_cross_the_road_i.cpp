#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<ll,ll>
#define mp make_pair
#define f first
#define s second
#define pb push_back

int main() {
	freopen("visitfj.in","r",stdin);
	freopen("visitfj.out","w",stdout);
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n; ll t; cin >> n >> t;
	vector<vector<pii>> adj(n*n); vector<ll> g(n*n);
	auto make_edge = [&](int a, int b) {adj[a].pb(mp(b,g[b]));};
	for (int i=0;i<n;i++) {
		for (int j=0;j<n;j++) {
			cin >> g[j+n*i]; 
		}
	}
	for (int i=0;i<n;i++) {
		for (int j=0;j<n;j++) {
			if (j > 0) {make_edge(j+n*i,j+n*i-1);}
			if (j < n-1) {make_edge(j+n*i,j+n*i+1);}
			if (i > 0) {make_edge(j+n*i,j+n*(i-1));}
			if (i < n-1) {make_edge(j+n*i,j+n*(i+1));}
		}
	}

	using T = pair<ll,pii>;
	priority_queue<T,vector<T>,greater<T>> pq; pq.push({0,{2,0}});
	vector<vector<ll>> dist(n*n,vector<ll>(3,LLONG_MAX)); dist[0][2] = 0;
	
	while (pq.size()) {
		T cur = pq.top(); pq.pop();
		if (dist[cur.s.s][cur.s.f] != cur.f) {continue;}
		for (pii x : adj[cur.s.s]) {
			// it is time to move
			if (cur.s.f == 1) {
				if (dist[x.f][2]>cur.f+t+x.s) {
					pq.push({dist[x.f][2]=cur.f+t+x.s,{2,x.f}});
				}
			} else {
				if (dist[x.f][(cur.s.f+1)%3]>cur.f+t) {
					pq.push({dist[x.f][(cur.s.f+1)%3]=cur.f+t,{(cur.s.f+1)%3,x.f}});
				}
			}
		}
	}
	cout << min(dist[n*n-1][0],min(dist[n*n-1][1],dist[n*n-1][2])) << '\n';
}
