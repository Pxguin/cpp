#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<ll,ll>
#define mp make_pair
#define f first
#define pb push_back
#define s second

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int n, k; cin >> n >> k;
	ll a; queue<ll> t;
	priority_queue<pii,vector<pii>,greater<pii>> pq;
	for (int i=0;i<n;i++) {cin >> a; t.push(a);}
	for (int i=0;i<k;i++) {pq.push({t.front(),i}); t.pop();}
	vector<vector<pii>> adj(k);
	ll prev = 0, time = 0, b = -1, b_time = -1;
	while (pq.size()) {
		pii cur = pq.top(); pq.pop();
		if (cur.f==time) {adj[cur.s].pb(mp(prev,time)); adj[prev].pb(mp(cur.s,time));}
		prev = cur.s; time = cur.f;
		if (t.size()) {pq.push({t.front()+time,cur.s}); t.pop();}
		else {if (b==-1) {b = prev; b_time = time;}}
	}
	
	vector<bool> ans(k); ans[b]=true;
	vector<ll> dist(k,-1); dist[b] = b_time;
	pq.push({b_time,b});
	cout << b_time << '\n';
	
	while (pq.size()) {
		pii cur = pq.top(); pq.pop();
		if (dist[cur.s] != cur.f) {continue;}
		for (pii x : adj[cur.s]) {
			if (x.s <= cur.f && x.s > dist[x.f]) {
				pq.push({dist[x.f]=x.s,x.f});
				ans[x.f]=true;
			}
		}
	}
	for (bool i : ans) {cout << i;}
}
