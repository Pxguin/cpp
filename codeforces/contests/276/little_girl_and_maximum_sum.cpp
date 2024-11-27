#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define v vector

int main() {
	ios::sync_with_stdio(false); cin.tie(0);

	int n, q; cin >> n >> q;
	v<ll> a(n);
	F0R(i,n) {cin >> a[i];}
	sort(a.begin(),a.end(),greater<>());

	v<int> ps(n+1,0);
	F0R(i,q) {
		int l, r; cin >> l >> r;
		ps[l-1]++; ps[r]--;
	}
	F0R(i,n) {ps[i+1] += ps[i];}
	sort(ps.begin(),ps.end(),greater<>());
	
	ll ans = 0;
	F0R(i,n) {ans += ps[i]*a[i];}
	cout << ans << '\n';
}