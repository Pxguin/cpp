#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define pb push_back
#define pii pair<int,int>
#define f first
#define s second
#define FOR(i, a, b, s) for (int i = (a); i < (b); i += s)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define sz(x) int((x).size())

void solve() {
	int n, q, a, b, u; cin >> n >> q;
	bool c[n+1]; vector<vector<int>> adj(n+1); 
	adj[0].pb(1); c[0] = 0;
	F0R(i,n) {cin >> c[i+1];}
	F0R(i,n-1) {cin >> a >> b; adj[a].pb(b); adj[b].pb(a);}

	vector<int> par(n+1,-1);
	vector<int> sum(n+1,0);
	set<pii> succ;

	stack<int> s; vector<bool> vis(n+1,false); s.push(0);
	while (s.size()) {
		int cur = s.top(); s.pop();
		vis[cur] = true;
		for (int x : adj[cur]) {
			if (!vis[x]) {
				s.push(x); 
				par[x] = cur; 
				if (c[x]) {sum[cur]++;}
			}
		}
	}
	vector<int> ok(4,0);
	F0R(i,n+1) {if (c[i]) {succ.insert({sum[i],i}); ok[min(3,sum[i])]++;}}

	while (q--) {
		cin >> u;
		c[u] ^= 1;
		int& cnt = sum[par[u]];
		if (c[u]) {
			cnt++;
			if (c[par[u]]) {
				succ.erase({cnt-1,par[u]}); succ.insert({cnt,par[u]});
				ok[min(cnt-1,3)]--; ok[min(cnt,3)]++;
			}
			succ.insert({sum[u],u}); ok[min(sum[u],3)]++;
		} else {
			cnt--;
			if (c[par[u]]) {
				succ.erase({cnt+1,par[u]}); succ.insert({cnt,par[u]});
				ok[min(cnt+1,3)]--; ok[min(cnt,3)]++;
			}
			succ.erase({sum[u],u}); ok[min(sum[u],3)]--;
		}

		int zero = ok[0], two_idx = 0, two = ok[2], other = ok[3];
		if (two) {two_idx = succ.lower_bound({2,-1})->s;}
		if (zero && zero <= 2 && other == 0 && ((two==1&&c[par[two_idx]]==0) || (zero!=2&&two==0))) {cout << "Yes\n";}
		else {cout << "No\n";}
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	int t; cin >> t;
	while (t--) {solve();}
}
