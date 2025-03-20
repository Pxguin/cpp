#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define pii pair<int,int>
#define mp make_pair
#define f first
#define s second
#define FOR(i, a, b, s) for (int i = (a); i < (b); i += s)
#define F0R(i, a) for (int i = 0; i < (a); i++)

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int n, m; cin >> n >> m;
	int a[n], c[m];
	int mx = 0, b;
	
	F0R(i,n) {cin >> a[i]; mx = max(mx, a[i]);}
	int dp[mx+1] = {0}; fill(dp+1,dp+mx+1,INT_MAX);
	F0R(i,n) {cin >> b; dp[a[i]] = min(dp[a[i]],a[i]-b);}
	F0R(i,m) {cin >> c[i];}

	pii mn = {INT_MAX,INT_MAX};
	FOR(i,1,(int)mx+1,1) {
		if (dp[i] < mn.s) {mn = {i-1,dp[i]};}
		dp[i] = (mn.s!=INT_MAX)+dp[max(0,i-mn.s)];
	} ll ans = 0;
	F0R(i,m) {
		if (c[i] > (int)mx) {
			int cnt = (c[i]-mx+mn.s-1)/mn.s;
			ans += dp[max(0,c[i]-cnt*mn.s)]+cnt;
		} else {ans += dp[c[i]];}
	} cout << ans*2 << '\n';
} 	
