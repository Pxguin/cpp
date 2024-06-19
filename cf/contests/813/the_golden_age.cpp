#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define pb push_back

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	ll x, y, l, r; cin >> x >> y >> l >> r;
	set<ll> years; years.insert(l-1); years.insert(r+1);
	vector<ll> a, b; a.pb(1); b.pb(1);
	ll a1 = x, b1 = y;
	for (; (double)1e18/a1 >= x && a1 != 1; a1 *= x) {a.pb(a1);}
	for (; (double)1e18/b1 >= y && b1 != 1; b1 *= y) {b.pb(b1);}
	if (a1 <= 1e18) {a.pb(a1);} if (b1 <= 1e18) {b.pb(b1);}
	for (ll a1 : a) {for (ll b1 : b) {if (a1+b1 >= l && a1+b1 <= r) {years.insert(a1+b1);}}}
	ll ans = 0;
	for (auto it = next(years.begin()); it != years.end(); it++) {ans = max(ans,*it-*(prev(it))-1);}
	cout << ans << '\n';
}
