#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define v vector

void solve() {
	int n, m, k; cin >> n >> m >> k;
	v<int> x(n), h(n);
	F0R(i,n) {cin >> h[i];}
	F0R(i,n) {cin >> x[i];}

	int lo = 1, hi = 1e9, mid = (lo+hi)/2;
	int ans = -1;
	while (lo <= hi) { // binary search on X
		v<int> r(n);
		v<int> start, stop;
		F0R(i,n) {
			r[i] = m-ceil((double)h[i]/mid); // [x-r, x+r] is the [l,r] range
			if (r[i]<0) {continue;} // any position inside [l,r] ensures this monster dies within X turns
			start.pb(x[i]-r[i]); stop.pb(x[i]+r[i]+1);
		}
		sort(start.begin(),start.end());
		sort(stop.begin(),stop.end());
		int p1 = 0, p2 = 0;
		bool flag = false;
		
		int ctr = 0;
		while (p1<start.size()) { // sweep line, find intersection of K ranges
			if (p2==stop.size() || start[p1]<stop[p2]) {ctr++; p1++;}
			else {ctr--; p2++;}
			if (ctr==k) {flag = true;}
		}
		if (flag) {ans = mid; hi = mid-1;}
		else {lo = mid+1;}
		mid = (lo+hi)/2;
	}
	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	
	int t; cin >> t;
	while (t--) {solve();}
}