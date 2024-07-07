#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define FOR(i, a, b, s) for (int i = (a); i < (b); i += s)
#define F0R(i, a) for (int i = 0; i < (a); i++)

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	int n, x; cin >> n >> x;
	ll a[n+1]; a[0]=0;
	map<ll,ll> ps;
	F0R(i,n) {cin >> a[i+1]; a[i+1] += a[i]; ps[a[i+1]]++;}
	ll ans = ps[x];
	F0R(i,n) {
		ps[a[i+1]]--;
		if (ps.count(a[i+1]+x)) {ans += ps[a[i+1]+x];}
	}
	cout << ans << '\n';
} 	