#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define chmin(a, b) a = min(a,b)

ll mod = 999983;
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());
const ll base = uniform_int_distribution<ll>(0, mod-1)(rng);

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	freopen("cownomics.in","r",stdin);
	freopen("cownomics.out","w",stdout);
	
	int n, m; cin >> n >> m;
	vector<vector<ll>> spots(n),plain(n);

	auto mul = [&](ll a, ll b) {return a*b;};
	vector<ll> exp={1};
	while (exp.size()<m) {exp.pb(mul(exp.back(),base)%mod);}

	string s;
	auto hsh = [&](vector<ll>& v) {
		v.pb(0);
		F0R(i,m) {v.pb((mul(v.back(),base)+s[i])%mod);}
	};
	auto get = [&](vector<ll>& v, int l, int r)->ll {
		ll ret (v[r+1]-mul(v[l],exp[r-l+1])%mod); 
		return (ret+mod)%mod;
	};

	F0R(i,n) {cin >> s; hsh(spots[i]);}
	F0R(i,n) {cin >> s; hsh(plain[i]);}	

	bool ok[1000000] = {false};
	int flag, ans = INT_MAX;
	int l = 0, h = m-1, sz = (l+h)/2;
	while (l<=h) {
		bool works = false;
		F0R(pos,m-sz) {
			F0R(i,n) {ok[get(spots[i],pos,pos+sz)] = true;}
			flag = 0;
			F0R(i,n) {flag |= ok[get(plain[i],pos,pos+sz)];}
			F0R(i,n) {ok[get(spots[i],pos,pos+sz)] = false;}
			if (!flag) {works = true; break;}
		} 
		if (works) {h = sz-1; ans = sz;}
		else {l = sz+1;}
		sz = (l+h)/2;
	} cout << ans+1 << '\n';
}