#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define pii pair<int,int>
#define mp make_pair
#define f first
#define s second
#define FOR(i, a, b, s) for (int i = (a); i < (b); i += s)
#define F0R(i, a) for (int i = 0; i < (a); i++)

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int n, m, a, b; cin >> n >> m;
	vector<int> deg(n,0);
	vector<vector<int>> adj(n);
	F0R(i,m) {
		cin >> a >> b; 
		deg[--a]++; deg[--b]++;
		adj[a].pb(b); adj[b].pb(a);
	} set<pii> pq;
	F0R(i,n) {pq.insert(mp(deg[i],i));}

	ll ans = 0;
	vector<pii> ord; vector<int> sz(n,1), link(n);
	F0R(i,n) {link[i]=i;}
	// remove edges by min degree
	while (pq.size()) {
		pii cur = *pq.begin(); pq.erase(cur);
		ord.pb(cur);
		deg[cur.s] = 0;
		for (int x : adj[cur.s]) {
			if (deg[x]) {pq.erase({deg[x],x}); pq.insert({--deg[x],x});}
		}
	}
	
	auto get = [&](int x) {while (link[x]!=x) {x = link[x];} return x;};
	auto unite = [&](int a, int b) {
		int x = get(a), y = get(b);
		if (x != y) {
			if (sz[x] < sz[y]) {swap(x,y);}
			sz[x] += sz[y];
			link[y] = x;
			return true;
		} return false;
	};
	// add edges back in reversed order
	while (ord.size()) {
		pii cur = ord.back(); ord.pop_back();
		deg[cur.s]++;
		for (int x : adj[cur.s]) {
			if (deg[x]) {unite(x,cur.s);}
		}
		ans = max(ans, (ll)(sz[get(cur.s)]*cur.f));
	} cout << ans << '\n';
} 	