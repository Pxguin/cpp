#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define F0R(i, a) for (int i = 0; i < (a); i++)

void solve() {
	int n, m, u, v; cin >> n >> m;
	vector<vector<int>> adj(n);

	F0R(i,n-1) {adj[i].pb(i+1);}
	F0R(i,m) {
		cin >> u >> v;
		adj[--u].pb(--v);
	}
	vector<int> dist(n,INT_MAX); dist[0] = 0;
	queue<int> q; q.push(0);
	while (q.size()) {
		int cur = q.front(); q.pop();
		for (int x : adj[cur]) {
			if (dist[x]==INT_MAX) {
				q.push(x);
				dist[x] = dist[cur]+1;
			}
		}
	}
	vector<int> mn(n,INT_MAX);
	multiset<int> ms;
	auto chmin = [&](int idx, int cand) {
		if (cand < mn[idx]) {
			if (mn[idx]!=INT_MAX) {ms.erase(ms.find(idx-mn[idx]));}
			ms.insert({idx-(mn[idx]=cand)});
		}
	};
	cout << 1; // always win from first island
	FOR(i,1,n-1) {
		chmin(i-1,dist[i-1]);
		for (int x : adj[i-1]) {chmin(x,dist[i-1]+1);}
		cout << !(*(ms.rbegin())-i>0);
	} cout << '\n';
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	
	int t; cin >> t;
	while (t--) {solve();}
}