#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	int n, q; cin >> n >> q;
	vector<ll> segtree(2*n, 0);
	int a, b;

	auto set = [&](int idx, ll val) {
		for (segtree[idx+=n]=val; idx > 1; idx >>= 1) {
			segtree[idx>>1] = segtree[idx]^segtree[idx^1];
		}
	};

	auto get = [&](int l, int r) { // [l,r)
		ll res = 0;
		for (l+=n,r+=n; l<r; l>>=1, r>>=1) {
			if (l&1) {res ^= segtree[l++];}
			if (r&1) {res ^= segtree[--r];}
		} return res;
	};
	for (int i=0;i<n;i++) {cin >> a; set(i,a);}

	for (int i=0;i<q;i++) {
		cin >> a >> b;
		cout << get(--a, b) << '\n';
	}
}
