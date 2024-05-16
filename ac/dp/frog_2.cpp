#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int n, k; cin >> n >> k;
	ll a[n];
	for (int i=0;i<n;i++) {cin >> a[i];}

	vector<ll> dp(n+k, LLONG_MAX); dp[0] = 0;
	for (int i=0;i<n;i++) {
		for (int j=1;j<=k;j++) {
			dp[i+j] = min(dp[i+j], dp[i]+abs(a[i+j]-a[i]));
		}
	}
	cout << dp[n-1] << '\n';
}