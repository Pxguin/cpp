#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define F0R(i, a) for (int i = 0; i < (a); i++)

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	
	int n, m, a, b; cin >> n >> m;
	vector<vector<int>> adj(n,vector<int>(n,0));
	F0R(i,m) {
		cin >> a >> b; a--; b--;
		adj[a][b] = adj[b][a] = 1;
	}

	vector<vector<ll>> dp((1<<n),vector<ll>(n,0));
	F0R(i,n) {dp[1<<i][i]=1;}
	vector<int> lsb((1<<n),0);
	FOR(mask,1,(1<<n)) {
		F0R(bit,n) {if (mask&(1<<bit)) {lsb[mask] = bit; break;}}
	}

	ll ans = 0;
	FOR(mask,1,(1<<n)) {
		FOR(last,lsb[mask],n) {
			FOR(nxt,lsb[mask],n) {
				if (!(mask&(1<<nxt)) && adj[last][nxt]) {
					dp[mask|(1<<nxt)][nxt] += dp[mask][last];
				}
			}
			if (adj[last][lsb[mask]]) {ans += dp[mask][last];}
		}
	} 
	cout << (ans-m)/2 << '\n';
}