#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define chmin(a, b) a = min(a,b)
#define chmax(a,b) a = max(a,b)

ll solve() {
	int n, z; cin >> n;
	vector<ll> h(n),a(n),t(n,-1);
	F0R(i,n) {cin >> h[i];}
	F0R(i,n) {cin >> a[i];}
	F0R(i,n) {cin >> z; t[n-z-1]=i;}

	ll lo = 0, hi = 1e18;
	F0R(i,n) {if (t[i]==-1) {return -1;}}
	FOR(k,1,n) {
		int i = t[k], j = t[k-1];
		if (h[i]>h[j]) { // find when it gets shorter
			if (a[i]>=a[j]) {continue;}
			ll cand = (h[i]-h[j]-1)/(a[j]-a[i]);
			if (cand>=0) {chmin(hi,cand);}
		} else { // find when it gets taller
			if (a[j]>=a[i]) {return -1;}
			ll cand = (h[j]-h[i])/(a[i]-a[j]) + 1;
			chmax(lo,cand);
		}
	} if (lo>hi) {return -1;}
	return lo;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);

	int t; cin >> t;
	while (t--) {cout << solve() << '\n';}
}