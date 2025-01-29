#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define F0R(i, a) for (int i = 0; i < (a); i++)

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	freopen("spainting.in","r",stdin);
	freopen("spainting.out","w",stdout);

	int n, m, k; cin >> n >> m >> k;
	vector<ll> dp(n+1,0);
	int mod = 1e9+7;
    
	vector<ll> exp(n+1,0); exp[0] = 1;
	FOR(i,1,n+1) {exp[i] = exp[i-1]*m%mod;}

	dp[k] = m;
	FOR(i,k+1,n+1) {
		dp[i] = (exp[i-k]-dp[i-k])*(m-1)%mod; // paint over everything
		dp[i] = (dp[i]+dp[i-1]*m)%mod; // paint under everything
	} cout << dp[n] << '\n';
}