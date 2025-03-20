#include <bits/stdc++.h>
using namespace std;

#define pii pair<int,int>
#define mp make_pair
#define f first
#define s second
#define chmin(a, b) a = min(a,b)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define v vector

void solve() {
	int n; cin >> n;
	v<pii> w(n), h(n);
	F0R(i,n) {
		cin >> h[i].f >> w[i].f;
		h[i].s = w[i].s = i;
	}
	v<pii> h2 = h;
	sort(h2.begin(),h2.end());
	v<pii> mn(n+1,{INT_MAX,INT_MAX}); // sort heights and find min width for each prefix
	F0R(i,n) {chmin(mn[i],w[h2[i].s]); chmin(mn[i+1],mn[i]);}
	v<int> ans(n,-2);

	F0R(i,n) {
		int it = upper_bound(h2.begin(),h2.end(),mp(h[i].f,-1)) - h2.begin();
		if (it && mn[it-1].f<w[h[i].s].f) {ans[h[i].s] = mn[it-1].s;} // check hh or ww

		it = upper_bound(h2.begin(),h2.end(),mp(w[i].f,-1)) - h2.begin();
		if (it && mn[it-1].f<h[w[i].s].f) {ans[w[i].s] = mn[it-1].s;} // check hw
	}
	F0R(i,n) {cout << ans[i]+1 << ' ';}
	cout << '\n';
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);

	int t; cin >> t;
	while (t--) {solve();}
}