#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define FOR(i, a, b, s) for (int i = (a); i < (b); i += s)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define pii pair<int,int>
#define mp make_pair
#define f first
#define s second

int main() {
	int m, n; cin >> m >> n;
	vector<pii> t(m);
	F0R(i,m) {cin >> t[i].f;}
	F0R(i,m) {cin >> t[i].s;}

	ll ans = 0, mod = 1e9+7;
	vector<ll> cur(m,0); cur[0]=1;
	F0R(i,n) {
		vector<ll> nxt(m,0);
		F0R(j,m) {
			if (!cur[j]) {continue;}
			F0R(k,m) {
				if (t[j].f&&t[k].s) {
					nxt[k] = (nxt[k]+cur[j]*(t[j].f*t[k].s%mod))%mod; 
				}
				if (t[j].s&&t[k].f) {
					nxt[k] = (nxt[k]+cur[j]*(t[j].s*t[k].f%mod))%mod;
				}
				if ((t[j].f&&t[k].f)) {
					nxt[k] = (nxt[k]+cur[j]*(t[j].f*t[k].f%mod))%mod;
				}
			}
		} 
		cur = nxt;
	} for (ll i : cur) {ans = (ans+i)%mod;}
	cout << ans << '\n';
}