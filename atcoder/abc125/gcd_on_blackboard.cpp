#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n; cin >> n; int a[n], ss[n];
	for (int i=0;i<n;i++) {cin >> a[i];} ss[n-1] = a[n-1];
	for (int i=n-2;i>=0;i--) {ss[i]=gcd(a[i],ss[i+1]);}
	int ans = max(ss[0],ss[1]); int cur = a[0];
	for (int i=1;i<n-1;i++) {ans = max(ans, gcd(cur,ss[i+1])); cur = gcd(cur,a[i]);}
	ans = max(ans, cur);
	cout << ans << '\n';
} // more concise: gcd 0 and x is just x
