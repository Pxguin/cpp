#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll mod = 998244353;

ll dp[5001] = {0};

ll mult(ll a, ll b) {return ((a%mod)*(b%mod))%mod;}
ll add(ll a, ll b) {return ((a%mod)+(b%mod))%mod;}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	ll ans = 0; dp[0] = 1;
	int n; cin >> n;
	vector<ll> a(n);
	for (int i=0;i<n;i++) {cin >> a[i];}
	sort(a.begin(), a.end());

	for (int i=0;i<n;i++) {
		for (int j=5000;j>=0;j--) {
			if (dp[j]) {
				dp[j+a[i]] = add(dp[j], dp[j+a[i]]);
				if (a[i] > j) {ans = add(ans,mult(dp[j],a[i]));}
				else {ans = add(ans,mult(dp[j],(j+a[i]+1)/2));}
			}
		}
	}
	cout << ans << '\n';
}
