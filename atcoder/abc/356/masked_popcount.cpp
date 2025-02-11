#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	ll n, m; cin >> n >> m;
	ll ans = 0, mod = 998244353;
	for (ll mask=1;mask<=61;mask++) {
		if ((1LL<<(mask-1))&m) {
			ll r = n%(1LL<<mask);
			ans = (ans+(n-r)/2)%mod;
			if (r>=(1LL<<mask)/2) {ans = (ans+max(0LL,r-(1LL<<mask)/2+1))%mod;}
		}
	} cout << ans << '\n';
}