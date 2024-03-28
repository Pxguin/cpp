#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll calc(ll a, ll b, ll m) {
	ll ans = 1;
	while (b > 0) {
		if (b%2) {ans = ans*a % m;}
		a = a*a % m;
		b /= 2;
	}
	return ans;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int n; cin >> n;
	ll a, b, c;
	while (n--) {
		cin >> a >> b >> c;
		cout << calc(a, calc(b, c, 1e9+6), 1e9+7) << '\n';
	}
}
