#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define FOR(i, a, b, s) for (int i = (a); i < (b); i += s)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define pii pair<int,int>
#define mp make_pair
#define f first
#define s second

struct Edge {
	int a, b, w;
	Edge (int a1, int b1, int w1) : a(a1), b(b1), w(w1) {};
	bool operator>(const Edge& y) {return w > y.w;}
};

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int n, m, q, a1, b1; cin >> n >> m >> q;
	vector<vector<pii>> adj(n);
	vector<Edge> edges;

	vector<int> link(n),sz(n,1);
	F0R(i,n) {link[i]=i;}
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
	F0R(i,m) {
		cin >> a1 >> b1;
		edges.pb(Edge(--a1,--b1,i));
	} sort(edges.begin(),edges.end(),greater<>());
	while (edges.size()) {
		Edge x = edges.back(); edges.pop_back();
		if (unite(x.a,x.b)) {adj[x.a].pb({x.b,x.w}); adj[x.b].pb({x.a,x.w});}
	}

	// calc queries
	int mxdist = ceil(log2(n));
	vector<vector<int>> par(n,vector<int>(mxdist+1,-2));
	vector<vector<int>> mx(n,vector<int>(mxdist+1,INT_MAX));
	vector<int> depth(n,-1), c(n,-1);
	int cn = 0;

	auto dfs = [&](auto&& dfs, int cur, int prev)->void{
		depth[cur] = depth[prev]+1;
		c[cur] = cn;
		for (pii x : adj[cur]) {
			if (x.f != prev) {
				dfs(dfs,x.f,cur); 
				par[x.f][0] = cur;
				mx[x.f][0] = x.s;
			}
		} return;
	};
	F0R(i,n) {if (par[i][0]==-2) {dfs(dfs,i,i); cn++;}}

	FOR(i,1,mxdist+1,1) {
		F0R(j,n) {
			int half = par[j][i-1];
			par[j][i] = (half==-2 ? -2 : par[half][i-1]);
			mx[j][i] = (half==-2 ? -2 : max(mx[j][i-1],mx[half][i-1]));
		}
	}
	auto kth_par = [&](int cur, int k) {
		pii ret = {cur,-1};
		F0R(i,mxdist+1) {
			if (k&(1<<i)) {
				k ^= (1<<i);
				ret.s = max(ret.s,mx[ret.f][i]);
				ret.f = par[ret.f][i];
				if (ret.f==-2) {break;}
			}
		} return (k ? mp(-2,-2) : ret);
	}; 
	auto lca = [&](auto&& lca, int x, int y)->int{
		if (c[x] != c[y]) {return -2;}
		if (depth[x] < depth[y]) {return lca(lca,y,x);}
		pii ret = kth_par(x,depth[x]-depth[y]); x = ret.f;
		if (x==y && x>=0) {return ret.s;}
		for (int i=mxdist;i>=0;i--) {
			if (x>=0&&y>=0 && (par[x][i] != par[y][i])) {
				ret.s = max(ret.s,max(mx[x][i],mx[y][i]));
				x = par[x][i];
				y = par[y][i];
			}
		} return ((x==-2||y==-2||ret.s==INT_MAX) ? -2 : max(ret.s,max(mx[x][0],mx[y][0])));
	};	
	F0R(i,q) {
		int u, v; cin >> u >> v;
		cout << lca(lca,--u,--v)+1 << '\n';
	}
}