#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int n, m; cin >> n >> m;
	ll s[n];
	for (int i=0;i<n;i++) {cin >> s[i];}

	for (int i=1;i<n;i++) {
		if (abs(s[i]-s[i-1]) > m) {
			if (s[i] < s[i-1]) {s[i] = s[i-1]-m;}
			else {s[i-1] = s[i]-m;}
		}
	}
	for (int i=n-1;i>0;i--) {
		if (s[i]-s[i-1] > m) {
			s[i-1] = s[i]-m;
		}
	}
	for (ll i : s) {cout << i << ' ';}
}