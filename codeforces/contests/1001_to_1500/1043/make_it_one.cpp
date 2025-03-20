#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define FOR(i, a, b, s) for (int i = (a); i < (b); i += s)
#define F0R(i, a) for (int i = 0; i < (a); i++)

ll mod = 1e9+7;
int MAX_N = 3e5;
vector<ll> fac(MAX_N+1);
vector<ll> inv(MAX_N+1);

ll mul(ll a, ll b) {return a*b%mod;}
ll sub(ll a, ll b) {return (a+mod-b)%mod;}

ll exp(ll a, ll b) {
	ll res = 1;
	while (b) {
		if (b%2) {res = mul(res,a);}
		b /= 2;
		a = mul(a,a);
	} return res;
}

void calc() {
	fac[0] = 1;
	FOR(i,1,MAX_N+1,1) {fac[i] = mul(fac[i-1],i);}
	inv[MAX_N] = exp(fac[MAX_N],mod-2);
	for (int i=MAX_N;i;i--) {inv[i-1] = mul(inv[i],i);}
}

ll C(int n, int k) {
	if (n<k) {return 0;}
	return mul(fac[n],mul(inv[k],inv[n-k]));
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);

	calc();
	int n, a; cin >> n;
	vector<int> freq(MAX_N+1,0);
	F0R(i,n) {cin >> a; freq[a]++;}
	vector<ll> dp(MAX_N+1,0);
	vector<ll> nxt(MAX_N+1,0);

	FOR(sz,1,8,1) {
		for (int gcd=MAX_N;gcd;gcd--) {
			int ctr = 0;
			FOR(mult,gcd,MAX_N+1,gcd) {ctr += freq[mult];}
			nxt[gcd] = C(ctr,sz);
			FOR(mult,2*gcd,MAX_N+1,gcd) {nxt[gcd] = sub(nxt[gcd],nxt[mult]);}
		}
		dp = nxt;
		nxt.assign(MAX_N,0);
		if (dp[1]) {cout << sz << '\n'; return 0;}
	} cout << "-1\n";
}