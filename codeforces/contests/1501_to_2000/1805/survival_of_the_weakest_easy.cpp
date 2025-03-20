#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define f first
#define s second
#define pll pair<ll,ll>

const ll MOD = 1000000007;

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n; cin >> n;

	vector<ll> a(n);
	for (int i=0;i<n;i++) {cin >> a[i];}
	ll ans = 0;

	ll powers[n]; powers[0] = 1;
	for (int i=1;i<n;i++) {
		powers[i] = powers[i-1]*2;
		powers[i] %= MOD;
	}

	// ok now do it
	while (n > 1) {
		sort(a.begin(), a.end());
		ans += (a[0]*powers[n-1]) % MOD; ans %= MOD;
		for (int i=n-1;i>=0;i--) {a[i] -= a[0];}
		vector<ll> nxt;
		priority_queue<pll, vector<pll>, greater<pll>> sums;
		vector<int> ptr(n);

		for (int i=0;i<n-1;i++) {
			ptr[i] = i+1;
			sums.emplace(a[i]+a[i+1], i);
		}
		n--;

		for (int i=0;i<n;i++) {
			pll mn = sums.top(); sums.pop();
			nxt.pb(mn.f);
			ptr[mn.s]++;
			if (ptr[mn.s] < n+1) {sums.emplace(a[mn.s]+a[ptr[mn.s]], mn.s);}
		}
		a = nxt;
	}
	ans += a[0];
	cout << ans % MOD;
}
