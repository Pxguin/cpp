#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define pii pair<int,int>
#define f first
#define s second
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define F0R(i, a) for (int i = 0; i < (a); i++)

int main() {
	ios::sync_with_stdio(false); cin.tie(0);

	int n; cin >> n;
	vector<int> a(n);
	F0R(i,n) {cin >> a[i];}

	int mn = INT_MAX; auto it = a.begin();
	for (auto i=a.begin();i!=a.end();i++) {
		if (*i<mn) {mn = *i; it = i;}
	} rotate(a.begin(),++it,a.end());
	reverse(a.begin(),a.end());
	
	vector<pii> st; // index, time in
	vector<ll> ps(n+1,0);
	a.pb(-1);
	F0R(i,n+1) {
		while (st.size()&&a[st.back().f]>=a[i]) {
			pii x = st.back(); st.pop_back();
			if (st.size()) { // [y.s+1,i-1]
				pii y = st.back();
				ps[y.s-y.f+1] += a[x.f]-a[y.f];
				ps[i-1-y.f +1] -= a[x.f]-a[y.f];
				st.back().s = i-1;
			}
		} st.pb({i,i});
	}
	ll ans = 0;
	F0R(i,n) {ans += a[i];}
	FOR(i,1,n+1) {ps[i]+=ps[i-1];}
	F0R(i,n) {
		ans -= ps[i+1];
		cout << ans << '\n';
	}
}