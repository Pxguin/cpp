#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define v vector

ll mod = 998244353;
void add(ll& a, ll b) {a = (a+b)%mod;}
void sub(ll& a, ll b) {a = (a+mod-b)%mod;}
void mul(ll& a, ll b) {a = a*b%mod;}

int MAX_A = 1000000;
v<int> prime(MAX_A+1,0);
void calc() {
	for (ll i=2;i<=MAX_A;i++) {
		if (!prime[i]) {
			for (ll j=i;j<=MAX_A;j+=i) {prime[j] = i;}
		}
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	
	calc();
	int n; cin >> n;
	v<ll> ans(n,0), a(n), div(MAX_A+1,0);
	F0R(i,n) {cin >> a[i];}
	ans[0] = 1;

	auto add_div = [&](int idx) { // add divisors
		for (ll j=1;j*j<=a[idx];j++) {
			if (a[idx]%j==0) {
				add(div[j],ans[idx]);
				if (j!=a[idx]/j) {add(div[a[idx]/j],ans[idx]);}
			}
		}
	};

	FOR(idx,1,n) {
		add_div(idx-1);
		v<int> fac;
		int last = -1, t = a[idx];
		while (t!=1) { // break down into unique primes
			if (prime[t]!=last) {fac.pb(prime[t]);}
			last = prime[t];
			t /= last;
		}

		FOR(i,1,(1<<(fac.size()))) { // go through each subset of primes (inclusion-exclusion)
			ll p = 1;
			F0R(j,fac.size()) {
				if ((1<<j)&i) {mul(p,fac[j]);}
			}
			if (p<=MAX_A) {
				if (__builtin_popcount(i)&1) {add(ans[idx],div[p]);}
				else {sub(ans[idx],div[p]);}
			}
		}
	}
	cout << ans[n-1] << '\n';
}