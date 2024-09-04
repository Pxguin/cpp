#include <bits/stdc++.h>
#include "garden.h"
#include "gardenlib.h"
using namespace std;

#define ll long long
#define pb push_back
#define pii pair<int,int>
#define f first
#define s second
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define F0R(i, a) for (int i = 0; i < (a); i++)

void count_routes(int n, int m, int p, int r[][2], int q, int g[]) {
	ios::sync_with_stdio(false); cin.tie(0);

	vector<pii> mx(n,{-1,-1});

	auto chmax = [&](int x, int v) {
		if (mx[x].f==-1) {mx[x].f=v;}
		else if (mx[x].s==-1) {mx[x].s=v;}
	};

	F0R(i,m) {chmax(r[i][0],r[i][1]); chmax(r[i][1],r[i][0]);}

	vector<int> dist(2*n,INT_MAX); dist[p] = 0; // to P
	vector<int> dist2(2*n,INT_MAX); dist2[n+p] = 0; // to P+N
	vector<bool> vis(2*n,false), vis2(2*n,false);
	vis[p] = true; vis2[n+p] = true;
	int cyc[2] = {0,0};

	auto find = [&](int cur) {
		int ret;
		if (cur >= n) {ret = (mx[cur-n].s==-1 ? mx[cur-n].f : mx[cur-n].s);}
		else {ret = mx[cur].f;}
		return (ret+n*(mx[ret].f==(cur%n)));
	};

	auto dfs = [&](auto& dfs, int cur, vector<int>& d, vector<bool>& v)->void {
		int nxt = find(cur);
		v[cur] = true;
		if (!v[nxt]) {dfs(dfs,nxt,d,v); d[cur] = d[nxt]+1;}
		else if (d[nxt]!=INT_MAX) {d[cur] = d[nxt]+1;}
		else {d[cur] = INT_MIN;}
	};

	F0R(i,2*n) {if (!vis[i]&&mx[i%n].f!=-1) {dfs(dfs,i,dist,vis);}}
	F0R(i,2*n) {if (!vis2[i]&&mx[i%n].f!=-1) {dfs(dfs,i,dist2,vis2);}}

	auto cycle = [&](auto& cycle, int cur, int src, int depth)->void {
		int nxt = find(cur); vis[cur] = true;
		if (!vis[nxt]) {cycle(cycle,nxt,src,depth+1);}
		else {if (nxt==src) {cyc[src/n] = depth+1;}}
	};
	if (mx[p].f!=-1) {
		vis.assign(2*n,false); cycle(cycle,p,p,0);
		vis.assign(2*n,false); cycle(cycle,p+n,p+n,0);
	}

	F0R(j,q) {
		int ans = 0; 
		int k = g[j];
		F0R(i,n) {
			ans += (dist[i]==k) + (dist2[i]==k);
			if (dist[i]>=0 && dist[i]!=INT_MAX && cyc[0] && (k-dist[i]>0)) {ans += !((k-dist[i])%cyc[0]);}
			if (dist2[i]>=0 && dist2[i]!=INT_MAX && cyc[1] && (k-dist2[i]>0)) {ans += !((k-dist2[i])%cyc[1]);}
		} answer(ans);
	} 
}