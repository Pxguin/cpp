#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define F0R(i, a) for (int i = 0; i < (a); i++)

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const ll mod = (1LL<<61)-1;
const ll b = uniform_int_distribution<ll>(0,1e5)(rng);

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	
	string s, h; cin >> s >> h;
	int n = s.size(), m = h.size();

	vector<ll> hsh = {0}, pow = {1};
	auto mul = [&](ll a, ll b)->__int128 {return (__int128)a*b;};
	F0R(i,m) {
		pow.pb(mul(pow.back(),b)%mod);
		hsh.pb((mul(hsh.back(),b)%mod+h[i])%mod);
	}
	auto get = [&](int i, int j) {
		ll ret = (hsh[j+1]-mul(hsh[i],pow[j+1-i])%mod)%mod;
		return (ret+mod)%mod;
	};
	unordered_map<ll,bool> ok;

	vector<int> freq(26,0);
	F0R(i,n) {freq[s[i]-'a']++;}

	if (m<n) {cout << 0 << '\n'; return 0;}
	vector<int> cfreq(26,0);
	F0R(i,n-1) {cfreq[(h[i]-'a')]++;}
	int ans = 0;

	auto check = [&](int idx) {
		int flag = 1;
		F0R(j,26) {flag &= (freq[j]==cfreq[j]);}
		if (flag) {
			ll cand = get(idx,idx+n-1);
			if (!ok.count(cand)) {ans += (ok[cand]=true);}
		} 
	};

	F0R(i,m-n+1) {
		cfreq[h[i+n-1]-'a']++;
		check(i);
		cfreq[h[i]-'a']--;
	} cout << ans << '\n';
}