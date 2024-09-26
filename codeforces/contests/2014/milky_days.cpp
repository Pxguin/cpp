#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define pii pair<int,int>
#define f first
#define s second
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define F0R(i, a) for (int i = 0; i < (a); i++)

void solve() {
	int n, m, k, d, a; cin >> n >> m >> k;
	queue<pii> gain, loss;
	F0R(i,n) {
		cin >> d >> a;
		gain.push({d,a});
		loss.push({d+k-1,a});
	} gain.push({1e9,0}); loss.push({1e9,0});

	int last = 1, ans = 0;
	deque<pii> cur;

	auto sim = [&](ll need)->void {
		ll left = need;
		while (left) {
			if (cur.empty()) {break;}
			pii x = cur.front(); cur.pop_front();
			if (x.s > left) {cur.push_front({x.f,x.s-left}); left = 0;}
			else {left -= x.s;}
		} ans += (need-left)/m;
	};

	while (max(gain.size(),loss.size()) > 1) {
		pii g = gain.front(), l = loss.front();
		if (g.f <= l.f) { // [last,g.f)
			sim((ll)(g.f-last)*m);
			cur.push_front(g);
			last = g.f;
			gain.pop();
		} else { // [last,l.f]
			sim((ll)(l.f-last+1)*m);
			if (cur.size() && cur.back().f == l.f-k+1) {cur.pop_back();}
			last = l.f+1;
			loss.pop();
		}
	} cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	
	int t; cin >> t;
	while (t--) {solve();}
}