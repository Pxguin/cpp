#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define FOR(i, a, b) for (int i = (a); i < (b); i++)

ll mod = 1e9+7;
ll exp(ll a, ll b) {
	ll res = 1;
	while (b) {
		if (b&1) {res = (res*a)%mod;}
		a = a*a%mod; b /= 2;
	} return res;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);

	ll k; string s; cin >> k >> s;
	ll n = s.size();
	
	vector<ll> fac(k+n+1,1), inv(k+n+1);
	FOR(i,1,k+n+1) {fac[i] = fac[i-1]*i%mod;}
	inv[k+n] = exp(fac[k+n],mod-2);
	for (int i=k+n;i;i--) {inv[i-1] = inv[i]*i%mod;}

	auto mul = [&](ll a, ll b)->ll {return (a*b)%mod;};
	auto C = [&](int n, int k)->ll {return fac[n]*inv[k]%mod*inv[n-k]%mod;};

	ll ans = 0;
	FOR(i,n,n+k+1){
		ans = (ans + mul(C(i-1,n-1),mul(exp(26,n+k-i),exp(25,i-n))))%mod;
    } cout << ans << '\n';

	/*
	for (int i=1;i<=k+1;i++) {
		ans = (ans + mul(exp(26,i-1),mul(C(n+k-i,n-1),exp(25,n+k-i-(n-1)))))%mod;
    }
	*/
}