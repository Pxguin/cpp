#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define F0R(i, a) for (int i = 0; i < (a); i++)

ll mod = 998244353;
ll add(ll a, ll b) {return (a+b)%mod;}
ll mul(ll a, ll b) {return a*b%mod;}
int MAX = 3e5;
vector<ll> inv(MAX+1), fac(MAX+1);

ll exp(ll a, ll b) {
	ll res = 1;
	while (b) {
		if (b&1) {res = mul(res,a);}
		b /= 2; a = mul(a,a);
	} return res;
}

void calc() {
	fac[0] = 1;
	FOR(i,1,MAX+1) {fac[i] = mul(fac[i-1],i);}
	inv[MAX] = exp(fac[MAX],mod-2);
	for (int i=MAX;i;i--) {inv[i-1] = mul(inv[i],i);}
}

ll C(ll n, ll k) {return mul(fac[n],mul(inv[k],inv[n-k]));}
ll P(ll n, ll k) {return mul(fac[n],inv[n-k]);}

struct hsh {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	calc();

	int n, m; cin >> n >> m;
	ll tot = 0, d;
	unordered_set<ll,hsh> ok;

	F0R(i,n) {
		ok.insert(tot);
		cin >> d; tot += d;
	}
	int p = 0; // pairs
	if (tot%2==0) {
		for (ll x : ok) {p += ok.count((x+tot/2)%tot);}
	} p /= 2;
	
	ll ans = 0;
	F0R(i,min(p+1,m+1)) {
		ll lh = mul(C(p,i),P(m,i));
		ll rh = mul(exp(m-i,n-2*i-(p-i)),exp(m-i-1,p-i));
		ans = add(ans,mul(lh,rh));
	} cout << ans << '\n';
}