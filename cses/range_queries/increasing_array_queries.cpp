#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define pii pair<int,ll>
#define f first
#define s second
#define F0R(i, a) for (int i = 0; i < (a); i++)

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	
	int n, q, l, r; cin >> n >> q;
	vector<ll> a(n);
	F0R(i,n) {cin >> a[i];}
	a.pb(1e9+1);
	
	vector<pair<pii,int>> query;
	F0R(i,q) {
		cin >> l >> r;
		query.pb({{--l,--r},i});
	} sort(query.begin(),query.end());

	vector<ll> ss; ss.pb(0);
	vector<int> st; st.pb(n);
	vector<ll> sum(n+1); sum[n]=0;
	vector<ll> ans(q);

	for (int i=n-1;i>=0;i--) {
		sum[i] = sum[i+1]+a[i]; // other suffix sums

		while (a[st.back()]<=a[i]) { // nearest larger values
			st.pop_back();
			ss.pop_back();
		}
		ss.pb(a[i]*(st.back()-i) + ss.back());
		st.pb(i);

		while (query.size() && query.back().f.f==i) { // query
			auto[cur,it] = query.back(); query.pop_back();
			l = cur.f; r = cur.s;

			int idx = upper_bound(st.rbegin(),st.rend(),r)-st.rbegin();
			idx = st.size()-idx-1;
			ll tot = ss[idx];
			if (st[idx]>r+1) {tot += a[st[idx+1]]*(st[idx]-(r+1));}
			ans[it] = (ss.back()-tot)-(sum[l]-sum[r+1]);
		}
	}
	for (ll x : ans) {cout << x << '\n';}
}