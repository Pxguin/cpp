#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define FOR(i, a, b, s) for (int i = (a); i < (b); i += s)
#define F0R(i, a) for (int i = 0; i < (a); i++)

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	int n; cin >> n;
	int a[n];
	vector<ll> m((int)1e6+1);
	F0R(i,n) {cin >> a[i];}
	sort(a,a+n);
	FOR(i,1,1e6+1,1) {
		int prev = 0;
		for (int j=(int)(1e6/i);j>0;j--) {
			int cur = ((a+n)-lower_bound(a,a+n,j*i));
			m[i] += (ll)(cur-prev)*j;
			prev = cur;
		}
	} ll ans = 0;
	for (int i : a) {
		ans += (--m[i]);
	} cout << ans << '\n';
}
