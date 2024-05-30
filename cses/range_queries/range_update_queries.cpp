#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	int n, q; cin >> n >> q;
	vector<ll> segtree(2*n, 0);

	auto set = [&](int a, ll b) {
		for (segtree[a+=n]+=b; a > 1; a >>= 1) {
			segtree[a>>1] = segtree[a]+segtree[a^1];
		}
	};
	auto get = [&](int b) {
		ll res = 0; int a=0;
		for (a+=n,b+=n; a<b; a>>=1,b>>=1) {
			if (a&1) {res += segtree[a++];}
			if (b&1) {res += segtree[--b];}
		} return res;
	};

	ll x, prev = 0;
	for (int i=0;i<n;i++) {
		cin >> x; set(i,x-prev); prev = x;
	}

	while (q--) {
		int t; cin >> t;
		if (t&1) {
			int a1, b1, u; cin >> a1 >> b1 >> u;
			set(--a1, u); if (b1<n) {set(b1, -u);}
		} else {int a1; cin >> a1; cout << get(a1) << '\n';}
	}
}
