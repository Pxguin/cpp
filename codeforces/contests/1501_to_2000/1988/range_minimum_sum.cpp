#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define pii pair<int,int>
#define mp make_pair
#define f first
#define s second
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define F0R(i, a) for (int i = 0; i < (a); i++)

void solve() {
	int n; cin >> n;
	pii a[n];
	F0R(i,n) {cin >> a[i].f; a[i].s = i;}
	sort(a,a+n);

	set<pii> rel; 
	rel.insert({-1,-1}); rel.insert({n,-1});
	ll sum[n];
	vector<ll> ps(n+1,0), ss(n+1,0);
	ll tot = 0;
	F0R(i,n) {
		pii cur = a[i];
		// calculate first/second min
		auto it = rel.insert({cur.s,cur.f}).f;
		ll l = prev(it)->f, r = next(it)->f;
		ll l2 = (l==-1 ? l : prev(prev(it))->f), r2 = (r==n ? r : next(next(it))->f);
		tot += -(sum[cur.s] = -(r-cur.s)*(cur.s-l)*cur.f);

		// update values in (l min, r min)
		if (l+1!=cur.s) {ps[l+1] -= (r-cur.s)*cur.f; ps[cur.s] += (r-cur.s)*cur.f;}
		if (r-1!=cur.s) {ss[cur.s] += (cur.s-l)*cur.f; ss[r-1] -= (cur.s-l)*cur.f;}

		// update values ending at first min
		if (l != -1) {sum[l] += cur.f*(r-cur.s)*((cur.s-l2-1)-(cur.s-l));}
		if (r != n) {sum[r] += cur.f*(cur.s-l)*((r2-cur.s-1)-(r-cur.s));}
	}
	F0R(i,n) {
		ps[i+1] += ps[i];
		ss[n-i-1] += ss[n-i];
	}

	F0R(i,n) {
		sum[i] += ps[i]+ss[i];
		cout << tot+sum[i] << ' ';
	} cout << '\n';
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	
	int t; cin >> t;
	while (t--) {solve();}
}