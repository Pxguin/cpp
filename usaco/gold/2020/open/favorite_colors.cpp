#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define F0R(i, a) for (int i = 0; i < (a); i++)

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	freopen("fcolor.in","r",stdin);
	freopen("fcolor.out","w",stdout);
	
	int n, m, a, b; cin >> n >> m;
	vector<vector<int>> adj(n);

	vector<int> par(n),sz(n,1);
	F0R(i,n) {par[i]=i;}
	F0R(i,m) {
		cin >> a >> b;
		adj[--a].pb(--b);
	}

	auto get = [&](auto& get, int x)->int {return (x==par[x]?x:par[x]=get(get,par[x]));};
	auto unite = [&](int x, int y) {
		x = get(get,x); y = get(get,y);
		if (x != y) {
			if (adj[x].size()<adj[y].size()) {swap(x,y);}
			
			while (adj[y].size()) {adj[x].pb(adj[y].back()); adj[y].pop_back();}
			par[y] = x; sz[x] += sz[y];
		}
	};
	queue<int> q;
	F0R(i,n) {if (adj[i].size()>1) {q.push(i);}}

	while (q.size()) {
		int cur = get(get,q.front()); q.pop();
		if (adj[cur].size()<=1) {continue;}
		
		int cand = adj[cur][0];
		q.push(cand);

		// unite all children !
		while (adj[cur].size()>1) {
			int sz = adj[cur].size();
			unite(cand,adj[cur].back());
			if (adj[cur].size()>1 && adj[cur].size()==sz) {adj[cur].pop_back();}
		}
	}
	vector<int> col(n,0);
	int c = 0;
	F0R(i,n) {
		int x = get(get,i);
		if (!col[x]) {col[x] = ++c;}
		cout << col[x] << '\n';
	}
}