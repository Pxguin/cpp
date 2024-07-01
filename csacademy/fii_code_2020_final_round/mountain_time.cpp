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

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int n, m; cin >> n >> m;
	int nm = n*m;
	int g[nm]; 
	vector<int> nodes(nm), ans(nm);
	F0R(i,nm) {cin >> g[i];}
	int par[nm],sz[nm]; vector<bool> vis(nm,false);
	F0R(i,nm) {par[i]=nodes[i]=i; sz[i]=1; ans[i]=g[i];}
	vector<vector<int>> mx(nm); F0R(i,nm) {mx[i].pb(i);}
	auto get = [&](int x) {while (par[x]!=x) {x=par[x];} return x;};
	sort(nodes.begin(),nodes.end(),[&](int x, int y) {return g[x]<g[y];});
	auto unite = [&](int x, int y) {
		int a = get(x), b = get(y);
		if (a==b) {return;}
		if (g[a]>g[b]) {swap(a,b);}
		if (g[a] != g[b]) {
			for (int i : mx[a]) {ans[i] = (ans[i]>g[x] ? ans[i]-g[x] : 0);}
		} else {
			if (mx[a].size()>mx[b].size()) {swap(a,b);}
			for (int i : mx[a]) {mx[b].pb(i);}
		} mx[a].clear();
		par[a] = b;
	};
	while (nodes.size()) {
		int cur = nodes.back(); nodes.pop_back();
		vis[cur] = true;
		int cx = cur%m, cy = cur/m;
		if (cx>0&&vis[cur-1]) {unite(cur,cur-1); }
		if (cx<m-1&&vis[cur+1]) {unite(cur,cur+1);}
		if (cy>0&&vis[cur-m]) {unite(cur,cur-m);}
		if (cy<n-1&&vis[cur+m]) {unite(cur,cur+m);}
	}
	F0R(i,nm) {
		cout << ans[i] << ' ';
		if (i%m==m-1) {cout << '\n';}
	}
}