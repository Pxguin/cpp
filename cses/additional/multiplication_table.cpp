#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll n;

bool check(ll m) {
	ll cur = 0;
	for (int i=1;i<=n;i++) {cur += min(m/i,n);}
	return (cur >= (n*n/2)+1);
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> n;
	
	ll l = 1, h = n*n, m = (l+h)/2;
	ll ans;
	while (l <= h) {
		if (check(m)) {
			ans = m; h = m-1;
		} else {l = m+1;}
		m = (l+h)/2;
	}
	cout << ans << '\n';
}
