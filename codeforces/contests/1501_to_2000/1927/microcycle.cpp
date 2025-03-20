#include <bits/stdc++.h>
using namespace std;

#define pii pair<int,int>
#define f first
#define s second
#define pb push_back
#define ll long long

struct Edge {
	int a, b, w;
	Edge(int a1, int b1, int w1) : a(a1), b(b1), w(w1) {}; 
	bool operator<(const Edge& y) {return w > y.w;}
};	


void solve() {
	int n, m; cin >> n >> m;
	int a1, b1, w1;
	vector<Edge> edges;
	vector<vector<int>> adj(n);
	for (int i=0;i<m;i++) {
		cin >> a1 >> b1 >> w1; a1--; b1--;
		edges.pb(Edge(a1, b1, w1));
	}

	int link[n], size[n];
	for (int i=0;i<n;i++) {link[i]=i; size[i]=1;}
	sort(edges.begin(), edges.end());

	auto find = [&](int x) {
		while (link[x] != x) {x = link[x];} 
		return x;
	};
	auto unite = [&](int x, int y) {
		int c1 = find(x), c2 = find(y);
		if (c1 != c2) {
			if (size[c1] < size[c2]) {swap(c1,c2);}
			size[c1] += size[c2];
			link[c2] = c1;
			return true;
		} return false;
	};
	Edge mn = Edge(1,1,1);
	for (Edge x : edges) {
		if (!unite(x.a, x.b)) {mn = x;}
		else {adj[x.a].pb(x.b); adj[x.b].pb(x.a);}
	}

	queue<int> q; q.push(mn.a);
	vector<int> dist(n, INT_MAX), par(n, -1);
	while (q.size()) {
		int cur = q.front(); q.pop();
		for (int x : adj[cur]) {
			if (dist[x] == INT_MAX) {
				dist[x] = dist[cur]+1;
				par[x] = cur;
				q.push(x);
			}
		}
	vector<int> ans;
	ans.pb(mn.a); ans.pb(mn.b);
	while (par[mn.b] != mn.a) {
		ans.pb(par[mn.b]);
		par[mn.b] = par[par[mn.b]];
	}
	cout << mn.w << ' ' << ans.size() << '\n';
	for (int i : ans) {cout << i+1 << ' ';}cout << '\n';

}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--) {solve();}
}
