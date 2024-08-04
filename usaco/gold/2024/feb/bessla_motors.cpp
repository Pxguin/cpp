#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define pii pair<ll,int>
#define pii2 pair<ll,pair<int,int>>
#define mp make_pair
#define f first
#define s second
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define F0R(i, a) for (int i = 0; i < (a); i++)

int main() {
	ios::sync_with_stdio(false); cin.tie(0);

	int n, m, c, r, k; cin >> n >> m >> c >> r >> k;
	int a1,b1,c1;
	vector<vector<pii>> adj(n);
	vector<set<int>> par(n); 
	F0R(i,m) {
		cin >> a1 >> b1 >> c1; --a1; --b1;
		adj[a1].pb({b1,c1}); adj[b1].pb({a1,c1});
	}

	priority_queue<pii2,vector<pii2>,greater<pii2>> pq;
	F0R(i,c) {
		pq.push({0,{i,i}});
	}
	while (pq.size()) {
		pii2 cur = pq.top(); pq.pop();
		if (par[cur.s.f].size()==k || par[cur.s.f].count(cur.s.s)) {continue;}
		par[cur.s.f].insert(cur.s.s);
		for (pii x : adj[cur.s.f]) {
			if (x.s+cur.f<=r) {pq.push({x.s+cur.f,{x.f,cur.s.s}});}
		}
	}
	vector<int> ans;
	FOR(i,c,n) {if (par[i].size()>=k) {ans.pb(i+1);}}
	cout << ans.size() << '\n';
	for (int i : ans) {cout << i << '\n';}
} 