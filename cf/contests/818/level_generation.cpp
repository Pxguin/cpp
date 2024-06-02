#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll n;

bool check(ll m) {
	ll t = (m+1)/2;
	return (t+(n-t)*(n-t-1)/2 >= m);
}

void solve() {
	cin >> n;
	ll l = n-1, h = 2*l, m = (l+h)/2; ll ans;

	while (l <= h) {
		if (check(m)) {l = m+1; ans = m;}
		else {h = m-1;}
		m = (l+h)/2;
	}
	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int q; cin >> q;
	while (q--) {solve();}
}
