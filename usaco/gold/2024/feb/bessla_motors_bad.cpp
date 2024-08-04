#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define pii pair<ll,int>
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
	vector<ll> dist(n,1e15);
	vector<set<int>> par(n); 
	//vector<int> start(n,-1);
	vector<int> link(n), sz(n,1), par(n,-1);
	F0R(i,m) {
		cin >> a1 >> b1 >> c1; --a1; --b1;
		adj[a1].pb({b1,c1}); adj[b1].pb({a1,c1});
	}
	F0R(i,n) {link[i] = par[i] = i;}
	priority_queue<pii,vector<pii>,greater<pii>> pq;
	F0R(i,c) {
		dist[i] = 0;
		par[i].insert(i);
		//start[i] = i;
		pq.push({0,i})
	}

	// Other solution (not sure about this one, honestly)
	/*auto add = [&](vector<set<int>>& v, int a, int b)->void {
		for (int i : v[a]) {
			if (v[b].size()==k) {break;}
			v[b].insert(i);
		}
	};*/

	/*while (pq.size()) {
		pii cur = pq.top(); pq.pop();
		if (dist[cur.s] != cur.f) {continue;}
		//cout << cur.f << ' ' << cur.s+1<<'\n';
		for (pii x : adj[cur.s]) {
			if (cur.f+x.s+dist[x.f] <= 2*r) {
				if (par[cur.s].size()!=k) {par[cur.s].insert(start[cur.s]);}
				if (par[x.f].size()!=k) {par[x.f].insert(start[x.f]);}
				add(par,cur.s,x.f); add(par,x.f,cur.s);
			} 
			if (cur.f+x.s < dist[x.f] && cur.f+x.s <= r) {
				pq.push({dist[x.f]=cur.f+x.s,x.f});
				start[x.f] = start[cur.s];
			}
		}
	}
	if (k==1) {
		F0R(i,n) {
			if (start[i]!=-1) {par[i].insert(start[i]);}
		}
	}*/
	
	// DSU + Dijkstra (I believe this works)
	auto get = [&](int x) {while (link[x]!=x) {x=link[x];} return x;};
	auto unite = [&](int a, int b) {
		int x = get(a), y = get(b);
		if (x != y) {
			if (sz[x] < sz[y]) {swap(x,y);}
			link[y] = x; sz[x] += sz[y]; 
			return x+1;
		} return 0;
	};

	while (pq.size()) {
		pii cur = pq.top(); pq.pop();
		if (dist[cur.s] != cur.f) {continue;}
		for (pii x : adj[cur.s]) {
			if (cur.f+x.s+dist[x.f] <= 2*r || (cur.f+x.s <= r)) {
				int res = unite(par[cur.s],par[x.f]);
				if (res) {par[(res-1 == cur.s ? x.f : cur.s)] = res-1;}
			}
			if (cur.f+x.s < dist[x.f]) {
				pq.push({dist[x.f]=cur.f+x.s,x.f});
			}
		}
	}
	
	vector<int> tot(n,0);
	F0R(i,c) {tot[get(i)]++;}
	vector<int> ans;
	FOR(i,c,n) {if (tot[get(i)]>=k) {ans.pb(i+1);}}
	cout << ans.size() << '\n';
	for (int i : ans) {cout << i << '\n';}
} 