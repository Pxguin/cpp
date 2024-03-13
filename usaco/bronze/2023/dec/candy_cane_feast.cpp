#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	int n, m; cin >> n >> m;
	ll a[n];
	ll c;
	for (int i=0;i<n;i++) {cin >> a[i];}
	while (m--) {
		cin >> c;
		ll e = 0;
		for (int i=0;i<n;i++) {
			if (a[i] > e) {
				ll add = min(a[i], c)-e;
				a[i] += add; e += add;
				if (e == c) {break;}
			}
		}
	}
	for (ll i : a) {cout << i << "\n";}
}