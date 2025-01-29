#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

int main() {
	freopen("time.in","r",stdin);
	freopen("time.out","w",stdout);
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int n, m, c, a, b; cin >> n >> m >> c;
	int t = 1000; // days before t^2 > 1000t

	vector<vector<int>> adj(n);
	vector<ll> money(n,0);
	vector<vector<ll>> dp(t+1, vector<ll>(n,0));
	// dp[i][j] max money if on ith day at city j

	for (int i=0;i<n;i++) {cin >> money[i];}
	for (int i=0;i<m;i++) {
		cin >> a >> b; a--; b--;
		adj[a].pb(b);
	}
	dp[0][0] = 1;

	for (int i=0;i<t;i++) {
		for (int j=0;j<n;j++) {
			if (dp[i][j]) {
				for (int k : adj[j]) {
					dp[i+1][k] = max(dp[i+1][k], dp[i][j]+money[k]);
				}
			}
		}
	}

	ll ans = 0;
	for (int i=0;i<=t;i++) {
		ans = max(ans, dp[i][0]-1-(c*i*i));
	}
	cout << ans << '\n';
}
