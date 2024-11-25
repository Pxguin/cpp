#include <bits/stdc++.h>
using namespace std;

#define F0R(i, a) for (int i = 0; i < (a); i++)
#define v vector

void solve() {
	int n; cin >> n;
	v<int> a(n), f(n+1,0);
	F0R(i,n) {cin >> a[i]; f[a[i]]++;} // store frequency

	int ans = 0;
	F0R(i,n+1) {ans += f[i]/2;} // sum of frequency divided by 2
	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);

	int t; cin >> t;
	while (t--) {solve();}
}