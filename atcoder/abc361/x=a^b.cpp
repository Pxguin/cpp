#include <bits/stdc++.h>
using namespace std;

#define ld long double
#define ll long long
#define pb push_back
#define chmax(a, b) a = max(a,b)
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define v vector

ll nth_root(ll n, ll rt) { // accurate floor of the nth root
	ll l = 2, h = n, m = (l+h)/2;
	ll ret;
	while (l<=h) {
		ll res = 1;
		F0R(i,rt) {
			if ((ld)n/res<m) {res=n; break;}
			res *= m;
		}
		if (res>=n) {h = m-1; ret = m;}
		else {l = m+1;}
		m = (l+h)/2;
	} ll res = 1;
	F0R(i,rt) {
		if ((ld)n/res<m) {ret--; break;} 
		res *= ret;
		if (res>n) {ret--; break;}
	} return ret;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);

	ll n; cin >> n;
	ll ans = 1;
	if (n<=3) {cout<<ans<<'\n'; return 0;}
	ll mx_b = log2(n);
	v<ll> range = {0,0}, fac(mx_b+1,0);

	FOR(i,2,mx_b+1) {
		range.pb(nth_root(n,i)-1);
		if (fac[i]==0) { // test if all prime factors are distinct
			FOR(j,1,mx_b+1) { 
				if (j*i<=mx_b) {
					if (fac[j*i]==-1||j%i==0) {fac[j*i]=-1;}
					else {fac[j*i]=fac[j]+1;}
				}
			}
		}
	}
	FOR(i,1,mx_b+1) { // c
		FOR(j,2,mx_b+1) { // d; cd=b
			if (i*j>mx_b) {continue;}
			if (fac[i]!=-1) {
				if (fac[i]%2) {ans -= range[i*j];} // sub
				else {ans += range[i*j];} // add
			}
		}
	} cout << ans << '\n';
}