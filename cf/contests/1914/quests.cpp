#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve() {
	int n, k; cin >> n >> k;
	ll a[n], b[n];
	for (int i=0;i<n;i++) {cin >> a[i];}
	for (int i=0;i<n;i++) {cin >> b[i];}

	ll ans = 0, mx = 0, cur = 0;
	for (int i=0;i<min(n,k);i++) {
		cur += a[i];
		mx = max(mx, b[i]);
		ans = max(ans, cur+mx*(k-i-1));
	}
	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	int t; cin >> t;
	while (t--) {solve();}
}