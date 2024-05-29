#include <bits/stdc++.h>
using namespace std;

#define ll long long

int n, k; 
vector<ll> a;

bool check(ll m) {
	ll cur = 0, groups = 1;
	for (int i=0;i<n;i++) {
		cur += a[i];
		if (cur > m) {groups++; cur = a[i];}
	} return (groups <= k);
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> n >> k; a.resize(n);

	ll l = 1, h = 2e14;
	for (int i=0;i<n;i++) {cin >> a[i]; l = max(l, a[i]);}
	ll m = (l+h)/2;
	ll ans;
	while (l <= h) {
		if (check(m)) {
			ans = m; h = m-1;
		} else {l = m+1;}
		m = (l+h)/2;
	}
	cout << ans << '\n';
}
