#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define pii pair<ll,int>
#define f first
#define s second
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define F0R(i, a) for (int i = 0; i < (a); i++)

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	freopen("fencedin.in","r",stdin);
	freopen("fencedin.out","w",stdout);
	
	int a, b, n, m; cin >> a >> b >> n >> m;
	vector<int> h(m),v(n);
	F0R(i,n) {cin >> v[i];}
	F0R(i,m) {cin >> h[i];}
	vector<pii> tot;
	h.pb(b); v.pb(a); h.pb(0); v.pb(0);
	ll ans = 0;

	sort(h.begin(),h.end()); sort(v.begin(),v.end());
	FOR(i,1,m+2) {h[i-1]=h[i]-h[i-1];}
	FOR(i,1,n+2) {v[i-1]=v[i]-v[i-1];}
	sort(h.begin(),h.end()); sort(v.begin(),v.end());
	ll n1 = n, m1 = m;
	ans += (h[0]*n1)+(v[0]*m1);
	FOR(i,1,m+1) {tot.pb({h[i],0});}
	FOR(i,1,n+1) {tot.pb({v[i],1});}
	sort(tot.begin(),tot.end());
	
	for (pii x : tot) {
		if (x.s) {ans += max(0LL,m1)*(x.f); n1--;}
		else {ans += max(0LL,n1)*(x.f); m1--;}
	}
	cout << ans << '\n';
}