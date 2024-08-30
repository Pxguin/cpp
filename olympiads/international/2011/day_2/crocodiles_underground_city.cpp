#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define pii pair<ll,ll>
#define f first
#define s second
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define F0R(i, a) for (int i = 0; i < (a); i++)

ll ans;

ll travel_plan(int n, int m, int r[][2], int l[], int k, int p[]) {
	ios::sync_with_stdio(false); cin.tie(0);

	vector<vector<pii>> adj(n);
	F0R(i,m) {
		adj[r[i][0]].pb({r[i][1],l[i]});
		adj[r[i][1]].pb({r[i][0],l[i]});
	}
	vector<pii> mn(n,{LLONG_MAX,LLONG_MAX});
	priority_queue<pii,vector<pii>,greater<pii>> pq;
	F0R(i,k) {
		mn[p[i]] = {0,0};
		pq.push({0,p[i]});
	} 
	vector<bool> vis(n,false);
	while (pq.size()) {
		pii cur = pq.top(); pq.pop();
		if (vis[cur.s]) {continue;}
		vis[cur.s] = true;

		for (pii qwerty : adj[cur.s]) {
			ll cand = qwerty.s+cur.f, x = qwerty.f;
			if (cand < mn[x].s) {
				if (cand <= mn[x].f) {
					mn[x].s = mn[x].f; mn[x].f = cand;	
				} else {mn[x].s = cand;}
				if (mn[x].s!=LLONG_MAX) {pq.push({mn[x].s,x});}
			}
		}
	} 
	ans = mn[0].s;
	return ans;
}