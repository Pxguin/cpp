#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define pii pair<int,int>
#define pb push_back
#define f first
#define s second

vector<vector<pii>> adj;
vector<bool> vis;
vector<int> ts;

void dfs(int cur) {
	vis[cur] = true;
	for (pii x : adj[cur]) {
		if (!vis[x.f]) {dfs(x.f);}
	}
	ts.pb(cur);
}

int main() {
	freopen("timeline.in","r",stdin);
	freopen("timeline.out","w",stdout);
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, m, c; cin >> n >> m >> c; 
	int a, b, x;
	int ans[n];
	adj.resize(n); vis.assign(n, false);
	for (int i=0;i<n;i++) {cin >> ans[i];}
	for (int i=0;i<c;i++) {
		cin >> a >> b >> x; a--; b--;
		adj[b].pb(mp(a,x));
	}
	for (int i=0;i<n;i++) {
		if (!vis[i]) {dfs(i);}
	}

	for (int i : ts) {
		int num = 0;
		for (pii x : adj[i]) {
			num = max(num, ans[x.f]+x.s);
		}
		ans[i] = max(ans[i], num);
	}
	for (int i : ans) {cout << i << '\n';}
}
