#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

ll mod = 1e9+7;

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, m, a, b; cin >> n >> m;
	vector<vector<int>> adj(n);
	for (int i=0;i<m;i++) {
		cin >> a >> b; 
		//adj[--a].pb(--b); use this line for push dp
		adj[--b].pb(--a);
	}
	vector<vector<ll>> dp((1<<n), vector<ll>(n,0));
	dp[1][0] = 1;
	// dp[i][j] = flights over subset i last city j

	/* push dp
	for (int i=1;i<(1<<n);i++) {
		if (!(i&1)) {continue;}
		if ((i&(1<<(n-1))) && (i!=((1<<n)-1))) {continue;}
		for (int j=0;j<n;j++) {    
			if (dp[i][j] == 0) {continue;}
			for (int k : adj[j]) {
				if (((1<<k)&i) == 0) {
					dp[(1<<k)|i][k] = (dp[i][j]+dp[(1<<k)|i][k])%mod;
				}
			}
		}
	}*/
	
	// pull dp
	for (int i=2;i<(1<<n);i++) {
		if (!(i&1)) {continue;} // ignore subsets which don't include city 1
		if ((i&(1<<(n-1))) && i!=((1<<n)-1)) {continue;} // ignore subsets including city n (except (1<<n)-1)
		for (int j=0;j<n;j++) {
			if ((i&(1<<j))==0) {continue;}
			for (int k : adj[j]) {
				if ((1<<k)&i) {
					dp[i][j] += dp[i^(1<<j)][k];
					dp[i][j] %= mod;
				}
			}
		}
	}
	cout << dp[(1<<n)-1][n-1] << '\n';
}
