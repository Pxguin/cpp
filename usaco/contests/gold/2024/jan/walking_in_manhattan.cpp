#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define pii pair<ll,ll>
#define mp make_pair
#define f first
#define s second
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define F0R(i, a) for (int i = 0; i < (a); i++)

int main() {
	ios::sync_with_stdio(false); cin.tie(0);

	ll n, q; cin >> n >> q;
	char t; ll p;
	vector<ll> h, v;
	F0R(i,n) {
		cin >> t >> p;
		if (t=='H') {h.pb(p);}
		else {v.pb(p);}
	}
	sort(h.begin(),h.end());
	sort(v.begin(),v.end());
	h.pb(2e9); h.pb(2e9+1); v.pb(2e9); v.pb(2e9+1);
	vector<ll> h2(h.size()-2),v2(v.size()-2);
	vector<ll> h3(h.size(),-1),v3(v.size(),-1);
	vector<ll> h4(h.size(),-1),v4(v.size(),-1);

	auto build = [&](vector<ll>& r, vector<ll>& r2, vector<ll>& r3, vector<ll>& r4)->void {
		pii last = {r.size()-2, r.size()-1};
		for (ll i=r.size()-3; i>=0; i--) {
			if (r[i]&1) {r2[i] = last.f; last.s = i;}
			else {r2[i] = last.s; last.f = i;}
		}
		ll cur = 0, ptr = 0;
		r3[ptr] = 0; r4[ptr] = 0; ptr++;
		while (r[cur] < 2e9) {
			r4[(cur=r2[cur])] = ptr;
			r3[ptr] = cur;
			ptr++;
		}
		F0R(i,r.size()-2) {
			if (r4[i]==-1) {r4[i] = r4[r2[i]]-1;}
		}
		// r = roads, r2 = nearest odd-distance road, r3 = path, r4 = index in path
	};
	build(h,h2,h3,h4); build(v,v2,v3,v4);
	while (h3.back()==-1) {h3.pop_back();}
	while (v3.back()==-1) {v3.pop_back();}

	while (q--) {
		ll x, y; ll d;
		cin >> x >> y >> d;
		auto c1 = lower_bound(h.begin(),h.end(),y), c2 = lower_bound(v.begin(),v.end(),x); // move to nearest intersection
		ll dir = 0; ll dist = 0;
		if (*c1==y && *c2!=x) {dir = 1;} // left/right
		else if (*c1!=y && *c2==x) {dir = 0;} // up/down
		dist = (*c1-y + *c2-x); d -= dist;
		y = c1-h.begin(); x = c2-v.begin();

		pii ans = {v[x],h[y]};
		ll low = 0; if (d<=0) {low = 1e8;}
		ll high = 2*min((h3.size()-h4[y]-1),(v3.size()-v4[x]-1));
		if (dist%2) {high += (v3.size()-v4[x]-1)>(high/2);}
		else {high += (h3.size()-h4[y]-1)>(high/2);}
		ll mid = (low+high)/2;

		while (low <= high) {
			ll dx = mid/2 + (mid&1&(dist%2)), dy = mid-dx;
			pii cand = {(dx ? v[v3[dx+v4[x]]]-v[x] : 0), (dy ? h[h3[dy+h4[y]]]-h[y] : 0)};
			if (cand.f+cand.s >= d) {
				ans = {cand.f+v[x],cand.s+h[y]};
				dir = (dist%2 ? (dx>dy) : (dx>=dy));
				high = mid-1;
			} else {low = mid+1;}
			mid = (low+high)/2;
		}

		ll over = (ans.f-v[x]+ans.s-h[y])-d;
		if (dir) {ans.f -= over;}
		else {ans.s -= over;}
		cout << ans.f << ' ' << ans.s << '\n';
	} 
} 