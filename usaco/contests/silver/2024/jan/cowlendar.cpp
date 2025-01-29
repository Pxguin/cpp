#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	unordered_set<ll> a;
	unordered_set<ll> mods;
	ll x;
	ll MAX_L = LLONG_MAX;
	for (int i=0;i<n;i++) {
		cin >> x; a.insert(x);
		MAX_L = min(MAX_L, x/4);
	}
	ll ans = 0;

	unordered_set<ll> divs;
	if (a.size() < 4) {
		ans = (1+MAX_L)*MAX_L/2;
	} else {
		for (auto i=a.begin(); i != next(a.begin(),4); i++) {
			for (auto j=next(i); j != next(a.begin(),4); j++) {
				ll diff = abs(*j-*i);
				for (ll p=1;p*p<=diff;p++) {
					if (!(diff % p)) {divs.insert(p); divs.insert(diff/p);}
				}
			}
		}

		for (ll l : divs) {
			if (l > MAX_L) {continue;}
			mods.clear();
			ans += l;
			for (ll i : a) {
				mods.insert(i%l);
				if (mods.size() > 3) {ans -= l; break;}
			}
		}
	}
	cout << ans << "\n";
}
