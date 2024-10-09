#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define F0R(i, a) for (int i = 0; i < (a); i++)

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	
	int n; cin >> n;
	vector<vector<int>> a(n,vector<int>(n));
	vector<vector<int>> adj(n,vector<int>(n,0));
	F0R(i,n) {
		F0R(j,n) {cin >> a[i][j];}
		F0R(j,n) {
			adj[--a[i][j]][i]=1;
			if (a[i][j]==i) {break;}
		}
	}

	vector<vector<ll>> dp((1<<n),vector<ll>(n,0));
	vector<ll> cyc(1<<n,0);
	F0R(i,n) {dp[1<<i][i]=1;}
	vector<int> lsb((1<<n),0);
	FOR(mask,1,(1<<n)) {
		F0R(bit,n) {if (mask&(1<<bit)) {lsb[mask] = bit; break;}}
	}

	FOR(mask,1,(1<<n)) {
		FOR(last,lsb[mask],n) {
			FOR(nxt,lsb[mask],n) {
				if (!(mask&(1<<nxt)) && adj[last][nxt]) {
					dp[mask|(1<<nxt)][nxt] += dp[mask][last];
				}
			} if (adj[last][lsb[mask]]) { // end cycle
				cyc[mask] += dp[mask][last];
				F0R(nxt,lsb[mask]) {dp[mask|(1<<nxt)][nxt] += dp[mask][last];} // new cycle
			}
		}
	} 
	cyc[0] = 1;
	int q; cin >> q;
	while (q--) {
		string s; cin >> s;
		int h = 0, g = 0;
		F0R(i,n) {
			if (s[i]=='H') {h|=(1<<i);}
			else {g|=(1<<i);}
		}
		cout << cyc[h]*cyc[g] << '\n';
	}
}