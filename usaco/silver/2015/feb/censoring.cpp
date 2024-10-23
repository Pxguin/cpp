#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define F0R(i, a) for (int i = 0; i < (a); i++)

ll mod = 1e9+7;
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());
ll b = uniform_int_distribution<ll>(0, mod-1)(rng);

ll add(ll a, ll b) {return (a+b)%mod;}
ll sub(ll a, ll b) {return (a+mod-b)%mod;}
ll mul(ll a, ll b) {return (a*b)%mod;}

int main() {
	freopen("censor.in","r",stdin);
	freopen("censor.out","w",stdout);
	ios::sync_with_stdio(false); cin.tie(0);
	
	string s, t; cin >> s >> t;
	int n = s.size(), m = t.size();
	ll hsh = 0;
	vector<ll> exp(max(n,m)+1,1);
	F0R(i,max(n,m)) {exp[i+1]=mul(exp[i],b);}
	F0R(i,m) {hsh = add(hsh,mul(t[i]-'a'+1,exp[i]));} // max power is M-1
	
	vector<ll> hsh_s(1,0);
	string ans; int k = 0;
	F0R(i,n) {
		k++; ans += s[i];
		hsh_s.pb(add(hsh_s.back(),mul(s[i]-'a'+1,exp[k-1])));
		if (k>=m) { // try deleting
			if (sub(hsh_s[k],hsh_s[k-m])==mul(hsh,exp[k-m])) {
				F0R(j,m) {
					hsh_s.pop_back(); k--;
					ans.pop_back();
				}
			}
		} 
	}

	cout << ans << '\n';
}