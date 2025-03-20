#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define FOR(i, a, b, s) for (int i = (a); i < (b); i += s)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define sz(x) int((x).size())

int n; ll f1, f2; ll ans = LLONG_MAX;
vector<ll> ext;

ll solve() {
	ll mx = 100002; ll mn = LLONG_MAX; 
	ll first = LLONG_MAX; ll first_prod = LLONG_MAX;
	vector<ll> dp(100002,LLONG_MAX); dp[1] = 0;
	// where index 100001 represents the minimum > 100000
	F0R(i,n) {
		for (int j=mx-1; j>=1; j--) {
			if (dp[j] != LLONG_MAX) {
				if (j*ext[i] < mx-1) { // <= 100000 case
					dp[j*ext[i]] = dp[j]|(1LL<<i);
				} else { // > 100000 case
					if (j*ext[i] < mn) { // new min
						mn = j*ext[i]; dp[mx-1] = dp[j]|(1LL<<i);
					}
				} ll idx = min(j*ext[i],mx-1);
				if (idx >= f1 && idx < first_prod) {
					first_prod = idx;
					first = dp[idx];
				}
			}
		} 
		if (first != LLONG_MAX) {
			ll prod = 1;
			F0R(mask,i+1) {
				if (!(first&(1LL<<mask))) {prod *= ext[mask];}
				if (prod >= f2) {return i+1;}
			}
		}
	} return LLONG_MAX;
}

void calc(int a, int b, int h, int w) {
	f1 = (h>=a ? 0 : ceil((double)a/h));
	f2 = (w>=b ? 0 : ceil((double)b/w)); // >= f is valid
	if (f1 == 0) {swap(f1,f2);}
	if (f1 == 0 && f2 == 0) {ans = 0;}
	ans = min(ans,solve());
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int a, b, h, w; cin >> a >> b >> h >> w >> n;
	ext.resize(n);
	F0R(i,n) {cin >> ext[i];}
	sort(ext.begin(),ext.end(),greater<int>());
	n = min(n,34);
	calc(a,b,h,w); calc(b,a,h,w);
	cout << (ans == LLONG_MAX ? -1 : ans) << '\n';
}
