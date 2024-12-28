#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define f first
#define s second
#define chmin(a, b) a = min(a,b)
#define chmax(a, b) a = max(a,b)
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define all(x) x.begin(),x.end()
#define v vector

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	freopen("cowpatibility.in","r",stdin);
	freopen("cowpatibility.out","w",stdout);
	
	ll n; cin >> n;
	map<v<int>,ll> tot;
	F0R(i,n) {
		int c[5];
		F0R(j,5) {cin >> c[j];}
		for (int mask=1;mask<(1<<5);mask++) { // go through all bitmasks
			v<int> s;
			F0R(j,5) {
				if (mask&(1<<j)) {s.pb(c[j]);}
			} sort(all(s));
			tot[s]++;
		}
	}
	ll ans = 0;
	for (auto x : tot) { // inclusion on subsets of flavors
		if (x.f.size()%2) {ans += x.s*(x.s-1)/2;}
		else {ans -= x.s*(x.s-1)/2;}
	} cout << n*(n-1)/2-ans << '\n';
}