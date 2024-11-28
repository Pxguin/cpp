#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define pii pair<int,int>
#define f first
#define s second
#define chmax(a, b) a = max(a,b)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define v vector

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	freopen("multimoo.in","r",stdin);
	freopen("multimoo.out","w",stdout);

	int n; cin >> n;
	v<v<int>> a(n,v<int>(n));
	F0R(i,n) {
		F0R(j,n) {cin >> a[i][j];}
	}
	v<v<int>> comp(n,v<int>(n,-1));
	v<v<pii>> edges;
	v<int> area, col;
	int c = 0, a_ = 0;
	auto ff = [&](auto& ff, int i, int j, int t)->void { // flood fill to find components
		if (i<0||i>=n||j<0||j>=n) {return;} 
		if (a[i][j]!=t) {edges[c-1].pb({i,j}); return;}
		if (comp[i][j]!=-1) {return;}
		comp[i][j] = c-1;
		a_++;
		ff(ff,i+1,j,t); ff(ff,i-1,j,t);
		ff(ff,i,j+1,t); ff(ff,i,j-1,t);
	};
	F0R(i,n) {
		F0R(j,n) {
			if (comp[i][j]==-1) {
				a_ = 0; c++;
				edges.pb({});
				ff(ff,i,j,a[i][j]);
				area.pb(a_); col.pb(a[i][j]);
			}
		}
	}
	int ans1 = 0, ans2 = 0;
	F0R(i,c) {chmax(ans1,area[i]);} // calculate single-cow answer

	v<map<int,v<int>>> adj(c);
	v<map<pii,bool>> vis(c); // dfs for every pair of colors (pair = state)
	F0R(i,c) { // build the graph,  edges between components if they are adjacent
		set<int> used;
		for (pii x : edges[i]) {
			int to = comp[x.f][x.s];
			if (used.count(to)) {continue;}
			used.insert(to);
			adj[i][a[x.f][x.s]].pb(to);

			pii state = {col[i],a[x.f][x.s]};
			if (state.f<state.s) {swap(state.f,state.s);}
			vis[i][state] = false;
		}
	}
	auto dfs = [&](auto& dfs, int cur, pii state)->int { // only go to colors in the state
		int ret = area[cur];
		vis[cur][state] = true;
		int nxt = (state.f==col[cur] ? state.s : state.f);
		for (int x : adj[cur][nxt]) {
			if (!vis[x][state]) {ret += dfs(dfs,x,state);}
		}
		return ret;
	};
	F0R(i,c) {
		for (auto x : vis[i]) {
			if (!x.s) {chmax(ans2,dfs(dfs,i,x.f));}
		}
	}

	cout << ans1 << '\n' << ans2 << '\n';
}