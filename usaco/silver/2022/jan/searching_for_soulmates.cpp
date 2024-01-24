#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll a, b;
ll power;
ll factor;

ll cmp() {
	ll add = b-factor*a;
	ll ret = 0;
	ll val = 1;

	for (int i=0;i<power;i++) {
		if (add & (1LL << i)) {ret++;}
	}
	for (int i=power;i<61;i++) {
		if (add & (1LL << i)) {ret += val;}
		val *= 2;
	}
	return ret;
}

void solve() {
	cin >> a >> b;
	ll ans = LLONG_MAX;
	ll temp = 0;
	power = max(0, (int)log2((long double)b/a));
	factor = pow(2,power);

	if (a <= b) {ans = temp+cmp()+power; power++; factor *= 2;}

	while (a != 1) {
		temp += a%2+1;
		a += a%2;
		a /= 2;
		if (a <= b) {
			if (power == 0) {ans = temp+cmp();}
			ans = min(ans, temp+cmp()+power);
			power++;
			factor *= 2;
		}
	}
	cout << ans << "\n";
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--) {solve();}
}
