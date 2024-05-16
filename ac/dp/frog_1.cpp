#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int n; cin >> n;
	ll a[n];
	for (int i=0;i<n;i++) {cin >> a[i];}

	vector<ll> dp(n+2, LLONG_MAX); dp[0] = 0;
	for (int i=0;i<n;i++) {
		dp[i+1] = min(dp[i+1], dp[i]+abs(a[i+1]-a[i]));
		dp[i+2] = min(dp[i+2], dp[i]+abs(a[i+2]-a[i]));
	}
	cout << dp[n-1] << '\n';
}