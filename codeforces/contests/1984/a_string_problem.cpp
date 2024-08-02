#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define FOR(i, a, b, s) for (int i = (a); i < (b); i += s)
#define F0R(i, a) for (int i = 0; i < (a); i++)

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const ll mod = 1e9+9;
const ll b = uniform_int_distribution<ll>(0,1e5)(rng);

void solve() {
	string s; cin >> s;
	int n = s.size();
	bool flag = false;
	vector<int> m;
	vector<ll> hsh = {0}, pow = {1};
	F0R(i,n) {
		pow.pb((pow.back()*b)%mod);
		hsh.pb(((hsh.back()*b)%mod+s[i])%mod);
	}
	auto get = [&](const int a, const int b)->ll {
		ll ret = (hsh[b+1]-hsh[a]*pow[b+1-a])%mod;
		return (ret+mod)%mod;
	};
	F0R(i,n) {
		if (s[i]!='a') {
			flag = true;
			m.pb(i);
		}
	}
	if (!flag) {cout << n-1 << '\n'; return;} 

	ll ans = 0;
	ll pref = m[0], suff = n-m.back()-1, mn;
	F0R(i,m.size()) {
		if (m.size()%(i+1)) {continue;}
		ll x = m[i]; flag = false;
		mn = LLONG_MAX;
		FOR(j,i+1,m.size(),i+1) {
			mn = min(mn,(ll)m[j]-m[j-1]-1);
			if (get(m[j],m[j+i])!=get(m[0],m[i])) {flag = true; break;}
		}
		if (flag) {continue;}
		ll pref2 = min(pref,mn); ll suff2 = min(suff,mn-pref2);
		ll suff3 = min(mn,suff);
		ans += (pref2+1)*(suff2+1);
		ll delta = min(pref2, suff3-suff2);
		ans += ((2*pref2+1-delta)*(delta)/2);
		pref2 -= delta; suff2 += delta;
		if (!pref2) {ans += (suff3+suff2+2)*(suff3-suff2)/2;}
	} cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	
	int t; cin >> t;
	while (t--) {solve();}
}