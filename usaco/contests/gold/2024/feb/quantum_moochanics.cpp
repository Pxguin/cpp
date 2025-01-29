#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define pb push_back
#define pii pair<ll,ll>
#define f first
#define s second
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define lb lower_bound
#define ub upper_bound

void solve() {
	int n; cin >> n;
	vector<pii> par(n);
	set<int> active; set<pair<ll,pii>> pairs;
	F0R(i,n) {cin >> par[i].f;}
	F0R(i,n) {cin >> par[i].s;}
	F0R(i,n) {active.insert(i);}

	auto calc = [&](int a, int b)->ll {
		ll half = ceil((ld)(par[b].f-par[a].f)/(par[a].s+par[b].s));
		return (half*2-(b%2));
	};
	auto init = [&](int a, int b)->pair<ll,pii> {return {calc(a,b),{a,b}};};
	F0R(i,n-1) {pairs.insert(init(i,i+1));}
	vector<ll> ans(n);

	while (active.size()) {
		auto[t,del] = *pairs.begin(); pairs.erase(pairs.begin());
		ans[del.f] = ans[del.s] = t;
		int i1 = -1, i2 = -1;
		auto it = active.lb(del.f), it2 = active.ub(del.s);
		if (it != active.begin()) {
			i1 = *prev(it);
			pairs.erase(init(i1,del.f));
		}
		if (it2 != active.end()) {
			i2 = *it2;
			pairs.erase(init(del.s,i2));
		}
		active.erase(del.f); active.erase(del.s);
		if (i1!=-1 && i2!=-1) {pairs.insert(init(i1,i2));}
	} 
	F0R(i,n-1) {cout << ans[i] << ' ';} cout << ans[n-1] << '\n';
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);

	int t; cin >> t;
	while (t--) {solve();}
}