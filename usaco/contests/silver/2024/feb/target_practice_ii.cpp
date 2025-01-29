#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll, ll>
#define pb push_back
#define eb emplace_back
#define s second
#define f first

vector<ll> pos, neg;
vector<pll> tr, br;

ll solve_min(vector<ll>& sign, vector<pll>& v) {
	sort(v.begin(), v.end(), [&](const pll& a, const pll& b) {
		if (a.s == b.s) {return a.f < b.s;}
		return a.s < b.s;
	});
	sort(sign.begin(), sign.end());
	ll l = LLONG_MIN, h = tr.back().s, m = (l+h)/2;
	ll ans;

	while (l <= h) {
		vector<ll> slopes;
		for (pll i : v) {slopes.pb((i.s-m)/i.f);}
		sort(slopes.begin(), slopes.end());
		bool flag = true;
		for (int i=0;i<slopes.size();i++) {
			if (slopes[i] < sign[i]) {flag = false; break;}
		}
		if (flag) {
			l = m+1; ans = m;
		} else {h = m-1;}
		m = (l+h)/2;
	}
	return ans;
}

void solve() {
	int n; cin >> n;
	ll x1, x2, y1, y2; cin >> x1;
	ll s;
	vector<ll> left;
	tr.clear(); br.clear(); pos.clear(); neg.clear();

	for (int i=0;i<n;i++) {
		cin >> y1 >> y2 >> x2;
		tr.eb(x2, -y2);
		br.eb(x2, y1);
		left.pb(y1); left.pb(y2);
	}
	sort(left.begin(), left.end());
	for (int i=0;i<4*n;i++) {
		cin >> s;
		if (s < 0) {neg.pb(-s);}
		else {pos.pb(s);}
	}
	if (min(neg.size(), pos.size()) < n) {cout << -1 << "\n"; return;}
	for (int i=0;i<pos.size()-n;i++) {
		br.eb(x1, *(left.end()-i-1));
	}
	for (int i=0;i<neg.size()-n;i++) {
		tr.eb(x1, -left[i]);
	}
	
	// search for min point
	ll low = solve_min(pos, br);
	
	ll high = -solve_min(neg, tr);
	cout << high-low << "\n";
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--) {solve();}
}
