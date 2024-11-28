#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define v vector

int MAX_N = 2e5;

v<ll> val(MAX_N), val2(MAX_N), sz(MAX_N,1), start(MAX_N), tour;
v<v<int>> adj(MAX_N);
v<ll> segtree(4*MAX_N,0);
int n;

void dfs(int cur, int par) {
	tour.pb(cur); start[cur] = tour.size()-1;
	val2[start[cur]] = val[cur];
	for (int x : adj[cur]) {
		if (x!=par) {
			dfs(x,cur);
			sz[cur] += sz[x];
		}
	}
}

void upd(int node, int cur, int l, int r, ll c) {
	if (l==r) {segtree[node] = c;}
	else {
		int m = (l+r)/2;
		if (cur<=m) {upd(node*2,cur,l,m,c);}
		else {upd(node*2+1,cur,m+1,r,c);}
		segtree[node] = segtree[2*node]+segtree[2*node+1];
	}
}
ll sum(int node, int ql, int qr, int l, int r) {
	if (l>r) {return 0;}
	if (ql==l&&qr==r) {return segtree[node];}
	int m = (ql+qr)/2;
	return sum(node*2,ql,m,l,min(r,m))+sum(node*2+1,m+1,qr,max(l,m+1),r);
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	
	int q; cin >> n >> q;

	F0R(i,n) {cin >> val[i];}
	F0R(i,n-1) {
		int a, b; cin >> a >> b;
		adj[--a].pb(--b);
		adj[b].pb(a);
	}
	dfs(0,0);

	F0R(i,n) {upd(1,i,0,n-1,val2[i]);}

	while (q--) {
		int t; cin >> t;
		if (t==1) {
			int s, x; cin >> s >> x;
			upd(1,start[s-1],0,n-1,x);
		} else {
			int s; cin >> s;
			cout << sum(1,0,n-1,start[s-1],start[s-1]+sz[s-1]-1) << '\n';
		}
	}
}