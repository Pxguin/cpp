#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define chmax(a, b) a = max(a,b)
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define v vector

ll mod = 1e9+7;
ll b = 58; // holy grail of bases

ll mul(ll a, ll b) {return a*b%mod;}
ll add(ll a, ll b) {return (a+b)%mod;}
ll sub(ll a, ll b) {return (a-b+mod)%mod;}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	
	int n; cin >> n;
	v<char> s(n+1);
	F0R(i,n) {cin >> s[i+1];}
	int m; cin >> m;
	v<char> t(m+1);
	F0R(i,m) {cin >> t[i+1];}
	int x; cin >> x;

	// do the hashes
	v<ll> hsh1(n+1,0), hsh2(n+2,0);
	v<ll> exp(max(n,m)+1,1); // update: max(n,m) always equals n
	F0R(i,max(n,m)) {exp[i+1]=mul(exp[i],b);}
	FOR(i,1,n+1) {hsh1[i]=add(hsh1[i-1],mul(exp[i],s[i]-'a'+1));}
	FOR(i,1,m+1) {hsh2[i]=add(hsh2[i-1],mul(exp[i],t[i]-'a'+1));}

	auto doit = [&](int i1, int i2) { // lcp calculation
		int l = 0, h = min(n-i1,m-i2), mid = 0;(l+h)/2;
		int ret = -1;
		while (l <= h) {
			if (sub(hsh1[i1+mid],hsh1[i1-1])==mul(exp[i1-i2],sub(hsh2[i2+mid],hsh2[i2-1]))) {ret = mid; l = mid+1;}
			else {h = mid-1;}
			mid = (l+h)/2;
		} return ret+1;
	};

	v<v<int>> dp(x+2,v<int>(n+1,-1)); // dp[i][j] = max satisfied in string t, given has made i pieces & considered up to index j in string s
	dp[0][0] = 0;
	F0R(i,x+1) {
		F0R(j,n) {
			if (dp[i][j]==-1 || dp[i][j]==m) {continue;}
			chmax(dp[i][j+1],dp[i][j]); // don't cut anything
			int d = doit(j+1,dp[i][j]+1); // it's optimal to take the longest string possible (which is the lcp)
			chmax(dp[i+1][j+d],dp[i][j]+d);
		}
	} 
	int ans = 0;
	F0R(i,x+1) {F0R(j,n+1) {chmax(ans,dp[i][j]);}}
	cout << (ans==m ? "YES" : "NO") << '\n';
}