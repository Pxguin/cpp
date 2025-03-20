#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define F0R(i, a) for (int i = 0; i < (a); i++)

ll mod = 998244353;
const int MAX_N = 1e6;
ll fac[MAX_N+1], inv[MAX_N+1];

ll exp(ll a, ll b) {
	ll res = 1;
	while (b) {
		if (b&1) {b--; res = (res*a)%mod;}
		a = (a*a)%mod; b /= 2;
	} return res;
}
void precalc() {
	fac[0] = 1;
	FOR(i,1,MAX_N+1) {fac[i] = (fac[i-1]*i)%mod;}
	inv[MAX_N] = exp(fac[MAX_N],mod-2);
	for (int i=MAX_N;i>=1;i--) {inv[i-1] = (inv[i]*i)%mod;}
}

ll C(ll n, ll k) {return fac[n]*inv[k]%mod*inv[n-k]%mod;}

void solve() {
	int l, n; cin >> l >> n;
	ll del = 0, ans = C(l,2*n);
	l -= 2*n;
	for (int i=0;i<=l/2;i++) {
		del = (del + C(i+n-1,i)*C(l-2*i+n,l-2*i)%mod)%mod;
	} ans = 2*((ans+mod-del)%mod)%mod;
	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);

	precalc();
	int t; cin >> t;
	while (t--) {solve();}
}