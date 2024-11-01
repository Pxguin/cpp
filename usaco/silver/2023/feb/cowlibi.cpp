#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<ll,ll>
#define f first
#define s second
#define F0R(i, a) for (int i = 0; i < (a); i++)

using Event = pair<ll,pii>;
ll sq(ll x) {return x*x;}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);

	int g, n; cin >> g >> n;
	ll x, y, t;
	vector<Event> events(g);
	F0R(i,g) {cin >> x >> y >> t; events[i] = {t,{x,y}};}
	sort(events.begin(),events.end());

	int ans = 0;
	F0R(i,n) {
		cin >> x >> y >> t;
		int flag = 0;
		Event e = {t,{-2e9,-2e9}};
		auto it = upper_bound(events.begin(),events.end(),e);
		if (it!=events.begin()) {
			it--;
			flag |= (sq(it->f-t)<(sq(it->s.s-y)+sq(it->s.f-x)));
			it++;
		}
		if (it!=events.end()) {
			flag |= (sq(it->f-t)<(sq(it->s.s-y)+sq(it->s.f-x)));
		} ans += flag;
	} cout << ans << '\n';

}