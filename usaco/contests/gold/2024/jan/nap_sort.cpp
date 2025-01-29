#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define chmin(a, b) a = min(a,b)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define all(x) x.begin(),x.end()
#define v vector

void solve() {
	int n; cin >> n;
	v<ll> a(n);
	F0R(i,n) {cin >> a[i];}
	sort(all(a));

	ll ans = a.back();
	ll l = 1, h = n, m = (l+h)/2;
	while (l <= h) {
		ll t = (m+1)*m/2, ctr = 0;
		int last = n-1;
		bool flag = true, f2 = false;
		for (int i=n-2;i>=0;i--) {
			if (a[i]>t || a[i]!=a[last]&&a[i]>=t) { 
				if (ctr==m-1) {flag = false;} // we force the last integer to Bessie, so relaxing contradictions as necessary
				last = i; 
				t -= ++ctr;
			} else {break;} // no contradictions left, so it works :)
		}
		if (flag) {h = m-1; chmin(ans,m*(m+1)/2);}
		else {l = m+1;}
		m = (l+h)/2;
	} cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);

	int t; cin >> t;
	while (t--) {solve();}
}