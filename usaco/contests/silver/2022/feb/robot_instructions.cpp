#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mp make_pair
#define pb push_back
#define f first
#define s second

struct hsh {
	size_t operator()(const pair<ll,ll> &p) const {
		return p.first * 239 + p.second;
	}
};

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	int xg, yg; cin >> xg >> yg;
	ll x, y;
	ll ans[n] = {0};
	pair<int,int> commands[n];
	for (int i=0;i<n;i++) {
		cin >> x >> y;
		commands[i] = mp(x,y);
	}
	ll k;

	auto solve = [&](int l, int r) {
		int len = r-l+1;
		vector<pair<pair<ll, ll>, ll>> ret;
		for (int mask=0;mask<(1<<len);mask++) {
			x = 0; y = 0; k = 0;
			for (int i=0;i<len;i++) {
				if (mask&(1<<i)) {
					x += commands[i+l].f;
					y += commands[i+l].s;
					k++;
				}
			}
			ret.pb(mp(mp(x,y), k));
		}
		sort(ret.begin(), ret.end());
		return ret;
	};

	auto left = solve(0, n/2-1);
	auto right = solve(n/2, n-1);
	unordered_map<pair<ll,ll>, map<ll,ll>, hsh> r;
	for (auto i : right) {
		r[i.f][i.s]++;
	}

	for (auto i : left) {
		x = xg-i.f.f;
		y = yg-i.f.s;

		auto it = r.find(mp(x,y));
		if (it != r.end()) {
			for (auto j : it->s) {
				ans[j.f+i.s-1] += j.s;
			}
		}
	}
	for (ll i : ans) {cout << i << "\n";}
}