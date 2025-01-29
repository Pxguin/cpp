#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define mp make_pair
#define f first
#define pb push_back
#define s second

vector<pll> c;
int n;
vector<vector<int>> adj;
vector<bool> vis;

ll sq(ll i) {return i*i;}

int dfs(int cur, int ctr) {
	vis[cur] = true;
	for (int x : adj[cur]) {
		if (!vis[x]) {ctr += dfs(x, 1);}
	}
	return ctr;
}

bool check(ll m) {
	vis = vector<bool>(n, false);
	adj = vector<vector<int>>(n);
	for (int i=0;i<n;i++) {
		for (int j=i+1;j<n;j++) {
			if (sq(c[j].f-c[i].f)+sq(c[i].s-c[j].s) <= m) {
				adj[i].pb(j); adj[j].pb(i);
			}
		}
	}
	return (dfs(0,1) == n);
}

int main() {
	freopen("moocast.in","r",stdin);
	freopen("moocast.out","w",stdout);
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> n; ll x, y;
	ll ans = 0;
	for (int i=0;i<n;i++) {
		cin >> x >> y;
		c.pb(mp(x,y));
	}
	auto sq = [&](ll x){return x*x;};
	
	ll h = 1e10, l = 0, m = (l+h)/2;
	while (l <= h) {
		if (check(m)) {h = m-1; ans = m;}
		else {l = m+1;}
		m = (l+h)/2;
	}
	cout << ans << '\n';
}