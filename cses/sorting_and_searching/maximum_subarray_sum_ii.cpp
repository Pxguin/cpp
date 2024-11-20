#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define chmax(a, b) a = max(a,b)
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define v vector

int main() {
	ios::sync_with_stdio(false); cin.tie(0);

	int n, a, b; cin >> n >> a >> b;
	v<int> x(n);
	F0R(i,n) {cin >> x[i];}

	v<ll> ps(n+1,0);
	F0R(i,n) {ps[i+1]=ps[i]+x[i];}

	multiset<ll> ms;
	ll ans = LLONG_MIN;
	F0R(i,b-a+1) {ms.insert(ps[i]);}

	FOR(i,1,n+1) {
		ms.erase(ms.find(ps[i-1])); // remove element
		if (i+(b-a)<=n) {ms.insert(ps[i+(b-a)]);} // insert new element
		if (i>=a) {
			chmax(ans,(*ms.rbegin())-ps[i-a]);
		}
	} cout << ans << '\n';
}