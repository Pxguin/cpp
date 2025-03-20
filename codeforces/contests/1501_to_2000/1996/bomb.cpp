#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define F0R(i, a) for (int i = 0; i < (a); i++)

void solve() {
	int n, k; cin >> n >> k;
	vector<ll> a(n), b(n);
	F0R(i,n) {cin >> a[i];}
	F0R(i,n) {cin >> b[i];}
	ll ans = -1;
	ll l = 0, h = 1e15, m = (l+h)/2;

	while (l <= h) {
		ll times = 0, cand = 0, waiting = 0;
		F0R(i,n) {
			if (m <= a[i]) {
				ll num = (a[i]-m)/b[i]; 
				ll low = a[i]-num*b[i];
				times += (a[i]+b[i]-m)/b[i];
				if ((a[i]-m)%b[i]==0) {waiting++; cand -= m;}
				cand += (a[i]+low)*(num+1)/2;
			}
		}

		if (times >= k) {
			cand += (k-times+waiting)*m;
			l = m+1; 
			ans = cand;
		}
		else {h = m-1;}
		m = (l+h)/2;
		// find max value such that >= k times
	}
	if (ans == -1) {
		ans = 0;
		F0R(i,n) {
			ll num = a[i]/b[i];
			ll low = a[i]-num*b[i];	
			ans += (a[i]+low)*(num+1)/2;
		}
	} cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	
	int t; cin >> t;
	while (t--) {solve();}
}