#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll MOD = 1e9+7;

void calc(ll a, ll b) {
	ll ans = 1;
	while (b > 0) {
		if (b%2) {ans = ans*a % MOD;}
		a = a*a % MOD;
		b /= 2;
	}
	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int n; cin >> n;
	ll a, b;
	while (n--) {
		cin >> a >> b;
		calc(a,b);
	}
}
