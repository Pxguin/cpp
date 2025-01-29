#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define v vector

int MAX_A = 1e6;
int mod = 1e9+7;
v<ll> fac(MAX_A+1,0), inv(MAX_A+1,0);
ll mul(ll a, ll b) {return a*b%mod;}

ll exp(ll a, ll b) {
	ll res = 1;
	while (b) {
		if (b&1) {res = mul(res,a);}
		b /= 2; a = mul(a,a);
	} return res;
}

void calc() {
	fac[0] = 1;
	F0R(i,MAX_A) {fac[i+1]=mul(fac[i],i+1);}
	inv[MAX_A] = exp(fac[MAX_A],mod-2);
	for (int i=MAX_A;i;i--) {inv[i-1]=mul(i,inv[i]);}
}

ll C(ll n, ll k) {return mul(mul(inv[n-k],inv[k]),fac[n]);}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	
	calc();
	int n; cin >> n;
	v<int> a(n);
	F0R(i,n) {cin >> a[i]; a[i]/=2;}

	v<ll> dp(n,0);
	dp[n-1] = 1;
	for (int i=n-2;i>=0;i--) {
		dp[i] = dp[i+1];
		if (a[i]<a[i+1]) {dp[i] = mul(dp[i],C(a[i+1]-1,a[i]-1));} // fill in all gaps
		else {dp[i] = mul(dp[i],C(a[i],a[i+1]));} // fill in all gaps (at least once)
	} cout << dp[0] << '\n';
}