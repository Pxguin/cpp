#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<ll,ll>
#define f first
#define s second


void solve() {
	int n; cin >> n;
	vector<pii> v(n);
	for (int i=0;i<n;i++) {cin >> v[i].f; v[i].s = i;}
	sort(v.begin(), v.end());
	vector<int> p(n);
	vector<bool> used(n,false), gone(n,false);
	for (int i=0;i<n;i++) {cin >> p[i]; p[i]--;}

	ll ans = v.back().f; int ans2 = 1;
	ll mn = ans;
	used[v.back().s] = true;
	v.pop_back();
	int cur = 1;

	while (v.size()) {
		pii x = v.back(); v.pop_back();
		if (!gone[x.s]) {
			cur++; 
			used[x.s] = true;
			gone[p[cur-2]] = true; 
			if (used[p[cur-2]]) {
				used[p[cur-2]] = false;
				// change this mushroom
				pii y;
				while (v.size()) {
					y = v.back(); v.pop_back();
					if (!gone[y.s]) {used[y.s] = true; break;}
				}
				if (used[y.s]) {
					// found new mushroom
					mn = y.f; 
					if (ans == mn*cur) {ans2 = min(ans2, cur);}
					else if (ans < mn*cur) {ans = mn*cur; ans2 = cur;}
				}
			} else {
				mn = x.f;
				if (ans == mn*cur) {ans2 = min(ans2, cur);}
				else if (ans < mn*cur) {ans = mn*cur; ans2 = cur;}
			}
		}
	}
	cout << ans << ' ' << ans2 << '\n';
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--) {solve();}
}
