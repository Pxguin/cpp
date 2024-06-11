#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<ll,int>
#define mp make_pair
#define pb push_back
#define f first
#define s second

int main() {
	freopen("shortcut.in","r",stdin);
	freopen("shortcut.out","w",stdout);
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int n, m, t, u, v, a; cin >> n >> m >> t;
	int c[n]; vector<vector<pii>> adj(n);
	for (int i=0;i<n;i++) {cin >> c[i];}
	for (int i=0;i<m;i++) {
		cin >> u >> v >> a;
		adj[--u].pb(mp(--v,a));
		adj[v].pb(mp(u,a));
	}
	using T = pair<pii,int>;
	priority_queue<T,vector<T>,greater<T>> pq; pq.push(mp(mp(0,0),0));
	vector<ll> dist(n,LLONG_MAX); dist[0] = 0;
	vector<int> nxt(n); for (int i=0;i<n;i++) {nxt[i]=i;}
	while (pq.size()) {
		T cur = pq.top(); pq.pop();
		if (dist[cur.s] != cur.f.f || nxt[cur.s] != cur.f.s) {continue;}
		for (pii x : adj[cur.s]) {
			if (dist[cur.s]+x.s == dist[x.f]) {
				if (cur.s < nxt[x.f]) {pq.push(mp(mp(dist[x.f],nxt[x.f]=cur.s),x.f));}
			} else if (dist[cur.s]+x.s < dist[x.f]) {
				pq.push(mp(mp(dist[x.f]=dist[cur.s]+x.s,nxt[x.f]=cur.s),x.f));
			}
		}
	}
	
	vector<int> deg(n+1,0); nxt[0] = n;
	for (int i=0;i<n;i++) {deg[nxt[i]]++;}
	queue<int> q;
	for (int i=0;i<n;i++) {if (!deg[i]) {q.push(i);}}
	while (q.size()) {
		int cur = q.front(); q.pop();
		if (cur == 0) {break;}
		c[nxt[cur]]+=c[cur]; 
		deg[nxt[cur]]--; if (!deg[nxt[cur]]) {q.push(nxt[cur]);}
	} ll ans = 0;
	for (int i=0;i<n;i++) {ans = max(ans, (ll)c[i]*(dist[i]-t));}
	cout << ans << '\n';
}
