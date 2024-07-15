#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define pii pair<ll,ll>
#define mp make_pair
#define f first
#define s second
#define FOR(i, a, b, s) for (int i = (a); i < (b); i += s)
#define F0R(i, a) for (int i = 0; i < (a); i++)

int main() {
	ios::sync_with_stdio(false); cin.tie(0);

	int n, k; cin >> n >> k;
	vector<vector<pii>> dp(n+4,vector<pii>(k+1,mp(0,0)));
	dp[0][0].f = 1; dp[2][1].f = 1;

	ll ans = 0, mod = 998244353;
	auto add = [&](ll a, ll b)->ll {return (a+b)%mod;};
	F0R(i,n) {
		F0R(j,k+1) {
			dp[i+1][j].s = add(dp[i+1][j].s,dp[i][j].s);
			dp[i+3][j+(j!=k)].s = add(dp[i+3][j+(j!=k)].s,add(dp[i][j].f,dp[i][j].s));
			dp[i+1][j+(j!=k)].f = add(dp[i+1][j+(j!=k)].f,add(dp[i][j].f,dp[i][j].s));
			if (i==n-2 && n!=2) {dp[n][j+(j!=k)].f = add(dp[n][j+(j!=k)].f,add(dp[i][j].f,dp[i][j].s));}
		}
	}
	cout << add(dp[n][k].f,dp[n][k].s) << '\n';
}