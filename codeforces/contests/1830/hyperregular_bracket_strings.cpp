#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define s second
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define v vector

mt19937 gen(std::chrono::steady_clock::now().time_since_epoch().count());
ll rng() {return uniform_int_distribution<ll>(0,INT64_MAX)(gen);}

int MAX_N = 4e5;
ll mod = 998244353;
v<ll> fac(MAX_N+1), inv(MAX_N+1);
v<ll> hsh(MAX_N+1);
v<ll> c(MAX_N+1,0); // catalan

ll mul(ll a, ll b) {return a*b%mod;}

ll exp(ll a, ll b) {
	ll res = 1;
	while (b) {
		if (b%2) {res = mul(res,a);}
		b /= 2;
		a = mul(a,a);
	} return res;
}

void init() {
	F0R(i,MAX_N+1) {hsh[i]=rng();}
	fac[0] = 1;
	FOR(i,1,MAX_N+1) {fac[i] = mul(fac[i-1],i);}
	inv[MAX_N] = exp(fac[MAX_N],mod-2);
	for (int i=MAX_N;i;i--) {inv[i-1]=mul(inv[i],i);}
	for (int i=0;i*2<=MAX_N;i++) {c[2*i]=mul(fac[2*i],mul(inv[i],inv[i+1]));}
}

void solve() {
	int n, k, l, r; cin >> n >> k;
	v<ll> ps(n+1,0);
	F0R(i,k) {
		cin >> l >> r; l--; r--;
		ps[l]^=hsh[i]; ps[r+1]^=hsh[i]; // start and end of a range
	}
	ps[0]^=hsh.back(); ps[n]^=hsh.back(); // the range [1,N]
	ll cur = ps[0], last = 0;
	map<ll,int> range;

	FOR(i,1,n+1) {
		if (ps[i]!=0) { // there is a new range
			range[cur] += i-last; // cur stores the hash of the current set of active ranges
			cur ^= ps[i];
			last = i;
		}
	} 
	ll ans = 1;
	for (auto h : range) {ans = mul(ans,c[h.s]);}
	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);

	init();
	int t; cin >> t;
	while (t--) {solve();}
}