#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
 
void solve() {
	int n; cin >> n;
	int a[n];
	for (int i=0;i<n;i++) {
		cin >> a[i];
	}
	sort(a, a+n);
	int g = max(1,a[n-1]-a[0]);
	for (int i=0;i<n;i++) {
		g = gcd(a[n-1]-a[i], g);
	}
 
	ll ans = 0;
	bool done = false;
 
	for (int i=n-2;i>=0;i--) {
		if (!done) {
			if (a[i] != a[n-1]-(n-i-1)*g) {
				ans += (n-i-1);
				done = true;
			}
			
		}
		ans += (a[n-1]-a[i])/g;
 
	}
	if (!done) {ans += n;}
	cout << ans << "\n";
}
 
int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	int t; cin >> t;
	while (t--) {solve();}
}