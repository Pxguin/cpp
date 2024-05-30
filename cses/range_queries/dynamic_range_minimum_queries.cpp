#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	int n, q; cin >> n >> q;
	vector<int> segtree(2*n, 0);
	int a, b, t;

	auto set = [&](int idx, int val) {
		// 2n & 2n+1 for two children
		// even index = left tree (1 index)
		for (segtree[idx+=n]=val; idx > 1; idx >>= 1) {
			segtree[idx>>1] = min(segtree[idx],segtree[idx^1]);
		}
	};

	auto get = [&](int l, int r) { // [l,r]
		int res = INT_MAX;
		for (l+=n,r+=n; l<=r; l>>=1, r>>=1) {
			// if l is on right of subtree, then its parent is not in range
			// so move it to the subtree on the right
			if (l%2==1) {res = min(res, segtree[l++]);}
			if (r%2==0) {res = min(res, segtree[r--]);}
		} return res;
	};
	
	for (int i=0;i<n;i++) {cin >> a; set(i,a);}

	for (int i=0;i<q;i++) {
		cin >> t >> a >> b;
		if (--t) {cout << get(--a,--b) << '\n';} 
		else {set(--a,b);}
	}
}
