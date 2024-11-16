#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define v vector

int MAX_A = 1e6;
ll mod = 1e9+7;
mt19937 mt((uint32_t)chrono::steady_clock::now().time_since_epoch().count());
ll rng() {return uniform_int_distribution<ll>(0,mod-1)(mt);}

v<int> prime(MAX_A+1,0);
void pleasecalcprimes() {
	for (ll i=2;i<=MAX_A;i++) {
		if (!prime[i]) {
			prime[i] = i;
			for (ll j=i*i;j<=MAX_A;j+=i) {prime[j]=i;}
		}
	}
}

ll sub(ll a, ll b) {return (a+mod-b)%mod;}
ll mul(ll a, ll b) {return a*b%mod;}
ll add(ll a, ll b) {return (a+b)%mod;}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	pleasecalcprimes();

	int n, q; cin >> n >> q;
	v<int> a(n);
	v<ll> random_array(MAX_A+1);
	v<ll> pref(n+1,0);
	v<int> freq(MAX_A+1,0);
	ll hsh = 0;

	F0R(i,MAX_A+1) {random_array[i] = rng();}

	auto change = [&](int idx)->void {
		hsh = sub(hsh,mul(random_array[idx],freq[idx]));
		freq[idx] = (freq[idx]+1)%3;
		hsh = add(hsh,mul(random_array[idx],freq[idx]));
	};

	F0R(i,n) {
		cin >> a[i];
		while (a[i]!=1) {
			change(prime[a[i]]);
			a[i] /= prime[a[i]];
		} pref[i+1] = hsh;
	}
	int l, r;
	F0R(i,q) {
		cin >> l >> r;
		cout << (pref[l-1]==pref[r] ? "Yes" : "No") << '\n';
	}
}