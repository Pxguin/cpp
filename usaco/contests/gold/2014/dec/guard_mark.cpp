#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

struct Cow {
	ll h, w, s;
	Cow(ll h1, ll w1, ll s1) : h(h1), w(w1), s(s1) {};
};

int main() {
	freopen("guard.in","r",stdin);
	freopen("guard.out","w",stdout);
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int n, mark; cin >> n >> mark;
	ll h1, w1, s1;
	vector<ll> dp(1<<n, -1);

	vector<Cow> a;
	for (int i=0;i<n;i++) {
		cin >> h1 >> w1 >> s1;
		a.pb(Cow(h1,w1,s1));
		dp[0] = LLONG_MAX;
		dp[1<<i] = s1;
	}

	for (int i=1;i<(1<<n);i++) {
		for (int j=0;j<n;j++) {
			if ((1<<j)&i) {
				int x = i^(1<<j);
				if (dp[x]-a[j].w >= 0) {
					dp[i] = max(dp[i], min(dp[x]-a[j].w,a[j].s));
				}
			}
		}
	}
	ll ans = -1;
	for (int i=1;i<(1<<n);i++) {
		ll h = 0;
		for (int j=0;j<n;j++) {if (i&(1<<j)) {h += a[j].h;}}
		if (h >= mark) {
			ans = max(ans,dp[i]);
		}
	}; 
	if (ans == -1) {cout << "Mark is too tall\n";}
	else {cout << ans << '\n';}
}
