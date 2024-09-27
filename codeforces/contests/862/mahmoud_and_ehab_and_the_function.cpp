#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define chmin(a, b) a = min(a,b)

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	
	int n, m, q; cin >> n >> m >> q;
	vector<ll> a(n), b(m);
	F0R(i,n) {cin >> a[i];}
	F0R(i,m) {cin >> b[i];}

	ll asum = 0; int fac = 1;
	F0R(i,n) {asum += a[i]*fac; fac*=-1;}
	vector<ll> ss(m+1,0);
	fac = -1;
	for (int i=m-1;i>=0;i--) { // ss has pos at end
		ss[i] = ss[i+1];
		ss[i] += b[i]*fac;
		fac *= -1;
	}
	vector<ll> bsum;
	F0R(j,m-n+1) {
		ll tot = ss[j]-ss[j+n]; // 0 minus, 1 plus
		if (n%2==(m-(j+n))%2) {tot *= -1;} // range: [j,j+n]; if parity of n = parity of M-(j+n) then it's ok 
		tot += asum;
		bsum.pb(tot);
	} sort(bsum.begin(),bsum.end());

	ll delta = 0, l1, r1, q1;
	auto query = [&]()->void {
		ll ret = LLONG_MAX;
		auto it = lower_bound(bsum.begin(),bsum.end(),-delta), it2 = it-1;
		if (it!=bsum.begin()) {chmin(ret,abs(*it2+delta));}
		if (it!=bsum.end()) {chmin(ret,abs(*it+delta));}
		cout << ret << '\n';
	};
	query();

	while (q--) {
		cin >> l1 >> r1 >> q1;
		ll add = (r1-l1+1)%2*q1;
		if (l1%2==0) {add*=-1;}
		delta += add;
		query();
	}
}