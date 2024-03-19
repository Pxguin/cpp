#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second
#define ll long long

vector<pair<int,int>> cows;
vector<ll> ps, ss;
int n;

void calc(vector<ll>& arr) {
	int mnx = INT_MAX, mxx = 0, mny = INT_MAX, mxy = 0;
	for (int i=0;i<n;i++) {
		mnx = min(mnx, cows[i].f); mxx = max(mxx, cows[i].f);
		mny = min(mny, cows[i].s); mxy = max(mxy, cows[i].s);
		arr[i+1] = (ll)(mxx-mnx)*(mxy-mny);
	}
}

ll solve() {
	sort(cows.begin(), cows.end());
	ps.clear(); ps.resize(n+1); ss.clear(); ss.resize(n+1);
	ps[0] = 0; ss[0] = 0;
	calc(ps);
	reverse(cows.begin(), cows.end());
	calc(ss);

	ll ret = LLONG_MAX;
	for (int i=0;i<n+1;i++) {ret = min(ps[i]+ss[n-i], ret);}
	return ret;
}


int main() {
	freopen("split.in","r",stdin);
	freopen("split.out","w",stdout);
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> n; cows.resize(n);

	for (int i=0;i<n;i++) {cin >> cows[i].f >> cows[i].s;}
	ll mnx = INT_MAX, mxx = 0, mny = INT_MAX, mxy = 0;
	for (pair<int,int>& i : cows) {
		mnx = min(mnx, (ll)i.f); mxx = max(mxx, (ll)i.f);
		mny = min(mny, (ll)i.s); mxy = max(mxy, (ll)i.s);
	}

	ll ans = solve();
	for (pair<int,int>& i : cows) {swap(i.f, i.s);}
	ans = min(ans, solve());

	ll area = (mxx-mnx)*(mxy-mny) - ans;
	cout << area << "\n";
}
